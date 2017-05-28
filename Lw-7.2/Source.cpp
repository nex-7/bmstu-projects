#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

void print(const std::vector<std::string> & words, const std::string & word, size_t count)
{
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == word) {
            if (count > i) {
                for (int j = 0; j < i; j++)
                    std::cout << words[j] << " ";
            }
            else {
                for (int j = i - count; j < i; j++)
                    std::cout << words[j] << " ";
            }

            std::cout << words[i] << " ";

            for (int j = i + 1; j <= i + count; j++) {
                if (j == words.size())
                    break;
                std::cout << words[j] << " ";
            }
            
            std::cout << std::endl;
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");
	std::ifstream fin;
    std::string filename;
    
    std::cout << "Введите имя файла: " << std::endl;
    std::cin >> filename;
    fin.open(filename, std::ios_base::in);

    if (fin.is_open()) {
        std::string word;
        std::cout << "Введите слово для поиска:" << std::endl;
        std::cin >> word;

        size_t n = 0;
        std::cout << "Сколько слов с каждой стороны?" << std::endl;
        std::cin >> n;

        std::map<std::string, size_t> counts;

        std::string buf;
        while (getline(fin, buf)) {
            std::vector<std::string> words;

            // разделение 
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

            // подсчёт кол-ва слов
            for (int i = 0; i < words.size(); i++) {
                if (counts.find(words[i]) != counts.end()) {
                    counts[words[i]]++;
                }
                else {
                    counts[words[i]] = 1;
                }
            }

            // печать слова с контекстом
            print(words, word, n);
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