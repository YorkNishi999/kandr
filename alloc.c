#define ALLOCSIZE 10000 // 使用可能な場所の大きさ

static char allocbuf[ALLOCSIZE]; // alloc のための記憶場所
static char *allocp = allocbuf; // 次の空き位置

char *alloc(int n) // ｎ文字へのポインタを返す
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { // can enter
		allocp += n;
		return allocp - n; // 古いｐ
	} else
		return 0;
}

void afree(char *p) // *pによって指される領域を開放する
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}