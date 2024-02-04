#include <Novice.h>
#include <Player.h>
#include <Enemy.h>
#include <BackGround.h>
#include <math.h>

const char kWindowTitle[] = "LC1A_29_ワタナベ_ナオ_タイトル";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	int Title = Novice::LoadTexture("./Resources/taitoru1.png");
	int Clear = Novice::LoadTexture("./Resources/CLEAR!.png");
	int Failed = Novice::LoadTexture("./Resources/FAILED.png");
	int Space = Novice::LoadTexture("./Resources/Let's Click.png");
	int Background = Novice::LoadTexture("./Resources/yokohaikei.png");
	
	Player* player = new Player;
	Enemy* enemy[2] = { new Enemy ,new Enemy };

	enemy[1]->SetPosition(1100.0f, 600.0f);

	BackGround* backGround[2] = { new BackGround,new BackGround };
	backGround[1]->SetPosition(1279.0f, 0.0f);

	enum scene {
		title,
		game,
		clear,
		gameover
	};
	int scene = title;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (scene) {
		case title:

			player->SetPlayerHP(4);
			for (int i = 0; i < 2; i++) {
				enemy[i]->SetisEnemyAlive(true);
				enemy[i]->SetPosition(900.0f, 300.0f);
			}
			
			enemy[1]->SetPosition(1100.0f, 600.0f);

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				scene = game;
			}

			break;
		case game:

			player->Update(keys, preKeys);
			//i = 敵の数
			//b = 弾の数
			for (int i = 0; i < 2; i++) {

				enemy[i]->Update(keys, preKeys);

				if (enemy[i]->GetisEnemyAlive_() == true) {
					for (int b = 0; b < 5; b++) {
						float EB_a = enemy[i]->GetPosition().x - player->bullet[b]->GetPosition().x;
						float EB_b = enemy[i]->GetPosition().y - player->bullet[b]->GetPosition().y;
						float EB_distance = sqrtf(EB_a * EB_a + EB_b * EB_b);
						if (EB_distance <= (enemy[i]->GetRadius() + player->bullet[b]->GetRadius())) {
							enemy[i]->SetisEnemyAlive(false);
						}
					}
					if (enemy[0]->GetisEnemyAlive_() == false
						&& enemy[1]->GetisEnemyAlive_() == false) {
						scene = clear;
					}

					//playerとenemyの当たり判定
					float PE_a = player->GetPosition().x - enemy[i]->GetPosition().x;
					float PE_b = player->GetPosition().y - enemy[i]->GetPosition().y;
					float PE_distance = sqrtf(PE_a * PE_a + PE_b * PE_b);
					if (PE_distance <= (player->GetRadius() + enemy[i]->GetRadius())) {
						player->SetPlayerHP(player->GetPlayerHP());
					}
					if (player->GetPlayerHP() == 0) {
						scene = gameover;
					}
				}

				backGround[i]->Update();

			}
			break;
		case clear:
			for (int b = 0; b < 5; b++) {
				player->bullet[b]->SetPosition(0.0f, 0.0f);
				player->bullet[b]->SetisBulletShot(false);
			}
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				scene = title;
			}

			break;
		case gameover:
			for (int b = 0; b < 5; b++) {
				player->bullet[b]->SetPosition(0.0f, 0.0f);
				player->bullet[b]->SetisBulletShot(false);
			}
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				scene = title;
			}
			break;

		
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		switch (scene) {
		case title:
			Novice::DrawSprite(0, 0, Title, 1, 1, 0.0f, WHITE);

			break;
		case game:

			for (int i = 0; i < 2; i++) {
				backGround[i]->Draw();
			}
			player->Draw();
			for (int i = 0; i < 2; i++) {
				enemy[i]->Draw();
			}
			break;
		case clear:
			Novice::DrawSprite(0, 0, Background, 1, 1, 0.0f, WHITE);

			Novice::DrawSprite(290, 260,Clear, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(415, 550, Space, 1, 1, 0.0f, WHITE);

			break;
		case gameover:
			Novice::DrawSprite(0, 0, Background, 1, 1, 0.0f, WHITE);

			Novice::DrawSprite(240, 260, Failed, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(415, 550, Space, 1, 1, 0.0f, WHITE);

			break;
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	delete player;
	for (int i = 0; i < 2; i++) {
		delete enemy[i];
		delete backGround[i];
	}
	return 0;
}