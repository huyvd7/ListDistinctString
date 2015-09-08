#include<stdio.h>
#include<string.h>

bool check(char *current) {
	char temp[13];
	char tempName[200];
	int compareResult = NULL;
	FILE *in = fopen("output.txt", "r");
	//If files doesn't exist, create a new one
	if (!in) {
		in = fopen("output.txt", "w");
		fclose(in);
		in = fopen("output.txt", "r");
	}
	//Compare current with each line in output to check distinct
	while (!feof(in)) {
		fgets(temp, 20, in);
		if (!temp) break;
		if (temp[sizeof(temp) - 1] == '\n') temp[sizeof(temp) - 1] = '\0';
		compareResult = strcmp(current, temp);
		if (compareResult == 0) return false;
	}
	fclose(in);
	//Print new entry
	FILE *out = fopen("output.txt", "a");
	fputs(current, out);
	fclose(out);
	return true;
}
int main() {
	FILE *in = fopen("input.txt", "r");
	char current[13];
	while (!feof(in)) {
		fgets(current, 20, in);
		if (current[sizeof(current) - 1] == '\n') current[sizeof(current) - 1] = '\0';
		check(current);
	}
	fclose(in);
	return 0;
}