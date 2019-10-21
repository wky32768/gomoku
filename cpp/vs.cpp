il pair <int,int> vs(int tot,int test) {
	For(gg,1,tot) {
		clr(a, 18, 18);
		int ping=0;

		while (!over()) {
			int tot = 0;
			For(i,1,15) For(j,1,15) if(a[i][j]) tot++;
			if (tot >= 225) {
				ping=1;
				break;
			}
			ans = run(a, 1, test);
			a[ans.first][ans.second] = 1;
			if (over()) {
				freopen("log.txt", "a", stdout);
				puts("AI win!");
				For(i, 1, 15) {
					For(j, 1, 15) {
						if (a[i][j] == 0) {
							putchar('_');
							putchar(' ');
						} else if (a[i][j] == 1) {
							putchar('O');
							putchar(' ');
						} else if (a[i][j] == 2) {
							putchar('X');
							putchar(' ');
						}
					}
					puts("");
				}
				cl_out();
				win1++;
				goto L3;
			}
			tot = 0;
			For(i,1,15) For(j,1,15) if(a[i][j]) tot++;
			if (tot >= 225) {
				ping=1;
				break;
			}
			ans = usr::ak(a, 2);
			a[ans.first][ans.second] = 2;
			if (over()) {
				freopen("log.txt", "a", stdout);
				puts("user win!");
				For(i, 1, 15) {
					For(j, 1, 15) {
						if (a[i][j] == 0) {
							putchar('_');
							putchar(' ');
						} else if (a[i][j] == 1) {
							putchar('O');
							putchar(' ');
						} else if (a[i][j] == 2) {
							putchar('X');
							putchar(' ');
						}
					}
					puts("");
				}
				cl_out();
				win2++;
				goto L3;
			}
		}
		freopen("log.txt","a",stdout);
		cout << "Game" << gg << "/" << tot << "\n\n\n";
		cl_out();
L3:
		;
		f_out("CON");
		if(gg%10==0) cout << gg << "/" << tot << "===" << win1 << " " << win2 << '\n';
		cl_out();
	}
	freopen("log.txt", "a", stdout);
	cout << win1 << " " << win2 << "\n";
	cl_out();
	return make_pair(win1,win2);
}
