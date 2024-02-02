#include <Novice.h>
#include <Player.h>
#include <Enemy.h>
#include <math.h>

const char kWindowTitle[] = "LC1A_29_ワタナベ_ナオ_タイトル";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player* player = new Player;
	Enemy* enemy[2] = { new Enemy ,new Enemy };

	enemy[1]->SetPosition(1100.0f, 600.0f);


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

				//playerとenemyの当たり判定
				float PE_a = player->GetPosition().x - enemy[i]->GetPosition().x;
				float PE_b = player->GetPosition().y - enemy[i]->GetPosition().y;
				float PE_distance = sqrtf(PE_a * PE_a + PE_b * PE_b);
				if (PE_distance <= (player->GetRadius() + enemy[i]->GetRadius())) {
					player->SetPlayerHP(player->GetPlayerHP());
				}
			}
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();
		for (int i = 0; i < 2; i++) {
			enemy[i]->Draw();
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
	}
	return 0;
}