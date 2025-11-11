#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
}


// 先頭にデータを追加
void push_front(list* l, node* p)
{
	// ToDo: ここにコードを追加
	if (l == NULL || p == NULL) return;
	p->pNext = l->header; //元の先頭を新しいノード'p'の次に来るよう設定する。
	l->header = p; //リストの先頭を新しいノード'p'に変更する。
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	// ToDo: ここにコードを追加
	if (!l) return; //(!l)は(l == NULL)と同義。リストが存在しない場合は終了する。
	node* temp = NULL; //初期化
	// 削除対象のノードがあるポインタを指定する。削除対象のノードを一時的に保持する'target'の宣言も同時に行う。
	// p == NULLならリストの先頭ノード'1->header'を削除する。'p'の次である場合は'p->pNext'
	node** target = (p == NULL) ? &l->header : &p->pNext; //二重ポインタ(ノードを指すポインタへのポインタ)
	temp = *target; //'target'が指す削除対象のノードを得る。

	if (!temp) return; //(!temp)は(temp == NULL)と同義。削除対象が存在しなければ終了する。
	*target = temp->pNext; //削除対象のノードを飛ばす。
}


// pの次のノードを取得
node* get_next(list* l, node* p)
{
	if (!p) return NULL;
	return p->pNext;

	return NULL;
}
