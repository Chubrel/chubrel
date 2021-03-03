bool task(int n, double& average) {
	int k;
	bool flag;
	int i = 0;
	do {
		std::cin >> k;
		flag = k % 2 == 0;
		i++;
	} while (flag && i != n);
	if (i != n) {
		int a1 = k;
		int a2;
		do {
			std::cin >> k;
			if (k % 2 != 0)
				a2 = k;
			i++;
		} while (i != n);
	}
}