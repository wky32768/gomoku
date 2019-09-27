unsigned long long rnd() {
	static unsigned long long i = (19260817) ^ ((int)(time(0))), j;
	i = i * i;
	i = i / 100000;
	i = i % 10000000000;
	j = i / 100000;
	return j;
}



il bool over() {
	For(i, 1, 15) For(j, 1, 15) {
		if (j + 4 <= 15) {
			if (a[i][j] != 0 && a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i][j + 2] && a[i][j + 2] == a[i][j + 3] && a[i][j + 3] == a[i][j + 4])
				return 1;
		}
		if (i + 4 <= 15) {
			if (a[i][j] != 0 && a[i + 1][j] == a[i][j] && a[i + 1][j] == a[i + 2][j] && a[i + 2][j] == a[i + 3][j] && a[i + 3][j] == a[i + 4][j])
				return 1;
		}
		if (i + 4 <= 15 && j + 4 <= 15) {
			if (a[i][j] != 0 && a[i][j] == a[i + 1][j + 1] && a[i + 1][j + 1] == a[i + 2][j + 2] && a[i + 2][j + 2] == a[i + 3][j + 3] && a[i + 3][j + 3] == a[i + 4][j + 4])
				return 1;
		}
		if (i + 4 <= 15 && j - 4 >= 1) {
			if (a[i][j] != 0 && a[i][j] == a[i + 1][j - 1] && a[i + 1][j - 1] == a[i + 2][j - 2] && a[i + 2][j - 2] == a[i + 3][j - 3] && a[i + 3][j - 3] == a[i + 4][j - 4])
				return 1;
		}
	}
	return 0;
}

il void f_in(char *a) {freopen(a, "r", stdin);}
il void f_out(char *a) {freopen(a, "w", stdout);}

#define cl_in() fclose(stdin)
#define cl_out() fclose(stdout)

pair<int, int> ans;
il void clr(vector<vector<int>/**/> &a, int x, int y) {
	a.resize(0);
	a.resize(x);
	for (int i = 0; i < x; i++) {
		a[i].resize(0);
		a[i].resize(y);
	}
}
