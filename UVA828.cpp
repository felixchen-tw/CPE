#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char L[128];
char msg[1024];
int N, n;
char ans[128];
bool isAns;

void solve(int idx, int m, int ansLen) {
	int len = strlen(L);
	if (msg[idx] == '\0') {
		ans[ansLen] == '\r';
		return; 
	} 
	else if (msg[idx] == ' ') {
		ans[ansLen] = ' ';
		ansLen++;
		idx++;
	}
	if (msg[idx] == L[m % len] && msg[idx + 2] == L[(m + 1) % len]) {
		bool flag = true;
		for (int i = 0; i < len; i++) {
			if (msg[idx + 1] == (L[i] - 'A' + N) % 26 + 'A')
				flag = false;
		}
		
		if (!flag) {
			ans[ansLen] = (msg[idx + 1] - N) < 'A' ? (msg[idx + 1] - N) + 26 : (msg[idx + 1] - N);
			ansLen++;
			m++;
			idx += 3;
			solve(idx, m, ansLen);
		}
		else
			isAns = false;	
	}
	else {
		bool flag = true;
		for (int i = 0; i < len; i++) {
			if (msg[idx] == (L[i] - 'A' + N) % 26 + 'A') {
				flag = 0;
				isAns = false;
				break;
			}
		}
		
		if (flag) {
			ans[ansLen] = (msg[idx] - N) < 'A' ? (msg[idx] - N) + 26 : (msg[idx] - N);
			ansLen++;
			idx++;
			solve(idx, m, ansLen);
		}
		
	} 
}

int main(){
	int count;
	scanf("%d", &count);
	while (count--) {
		scanf("\n%[^\n]", &L);
		scanf("%d %d", &N, &n);
		int i;
		for (i = 0; i < n; i++) {
			memset(msg, '\0', 1024);
			memset(ans, '\0', 128);
			getchar();
			scanf("%[^\n]", msg);
			isAns = true;
			solve(0, 0, 0);
            if(isAns) {
                printf("%s\n", ans);
            }
            else {
                printf("error in encryption\n");
            }	
		}
		if (count)
			printf("\n");
	}
	return 0;
}