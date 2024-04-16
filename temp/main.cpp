

int main() {
	int ar[100];

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100 - 1; j++) {
			if (ar[j] > ar[j+1]) {
				int temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
			}
		}
	}
}
