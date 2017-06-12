#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

int main()
{
	setlocale(LC_ALL, "rus");
	std::ifstream fin;
	std::string filename;

	std::cout << "¬ведите им€ файла: " << std::endl;
	std::cin >> filename;
	fin.open(filename, std::ios_base::in);

	if (fin.is_open()) {
		std::map<std::string, size_t> counts;

		std::string buf;
		while (getline(fin, buf)) {
			std::vector<std::string> words;

			// разделение на слова
			std::string buf2;
			for (size_t i = 0; i < buf.size(); i++) {
				if (buf[i] == ' ' || buf[i] == '.' || buf[i] == ',' || buf[i] == '!' || buf[i] == '?') {
					if (!buf2.empty()) {
						words.push_back(buf2);
						buf2.clear();
					}
				}
				else {
					buf2 += buf[i];
				}
			}
			if (!buf2.empty())
				words.push_back(buf2);

			// подсчЄт кол-ва слов
			for (int i = 0; i < words.size(); i++) {
				if (counts.find(words[i]) != counts.end()) {
					counts[words[i]]++;
				}
				else {
					counts[words[i]] = 1;
				}
			}
		}
		std::cout << std::endl;

		// вывод кол-в
		for (auto& count : counts) {
			std::cout << count.first << " " << count.second << std::endl;
		}

		fin.close();
	}
	system("pause");
	return 0;
}