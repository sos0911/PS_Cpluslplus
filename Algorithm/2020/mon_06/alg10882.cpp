// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int nofw;
	cin >> nofw;
	string input;
	cin >> input;
	input.erase(2, 1);

	int local_tar_hour = stoi(input.substr(0, 2));
	int local_tar_min = stoi(input.substr(2));

	cin >> input;
	float utc_tar; // target utc
	if (input[3] == '+')
		utc_tar = stof(input.substr(4));
	else
		utc_tar = -(stof(input.substr(4)));
	for (int i = 0; i < nofw; i++) {
		cin >> input;
		float curutc;
		if (input[3] == '+')
			curutc = stof(input.substr(4));
		else
			curutc = -stof(input.substr(4));
		float diff = (curutc - utc_tar);
		int hour = local_tar_hour, min = local_tar_min;
		if (diff >= 0)
			hour = (local_tar_hour + (int)diff) % 24;
		else
			hour = (local_tar_hour + (int)diff) < 0 ? (local_tar_hour + (int)diff) + 24 : (local_tar_hour + (int)diff);

		if ((int)(diff * 10) % 10) {
			if (diff >= 0) {
				if (min + 30 >= 60) {
					min = (min + 30) % 60;
					hour = (hour + 1) % 24;
				}
				else
					min = (min + 30) % 60;
			}
			else {
				if (min - 30 < 0) {
					min = min - 30 + 60;
					hour = hour - 1 < 0 ? hour - 1 + 24 : hour - 1;
				}
				else
					min = min - 30;
			}
		}

		//cout << hour << " " << min << '\n';
		
		string ans_str = to_string(hour) + to_string(min);
		if (to_string(hour).size() < 2)
			ans_str.insert(0, 2 - to_string(hour).size(), '0');
		if (to_string(min).size() < 2)
			ans_str.insert(2, 2 - to_string(min).size(), '0');
		cout << ans_str.substr(0, 2) + ":" + ans_str.substr(2) << '\n';
	}

	return 0;
}