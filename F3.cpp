/*******************************************
Pāvels Petrovs, pp23055
F3. Dots teksta fails. Uzrakstīt programmu, kura pārveido doto failu tā, lai katrā rindiņā būtu ne vairāk kā n simboli (10<=n<=80). Vienu vārdu nedrīkst sadalīt daļās, tam jāatrodas vienā rindiņā. Vārds jāraksta jaunā rindiņā tikai tad, ja tas nesaiet iepriekšējā. Drīkst uzskatīt, ka vārda garums failā nepārsniedz n simbolus. Par vārdu uzskatīt patvaļīgu simbolu virkni, kas atdalīta ar tukšumiem vai pieturas zīmēm (punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme).
Programma izveidota: 2024/02/25
*******************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    fstream f1, f2;
    f1.open("F3.txt", ios::in);
    f2.open("F3_copy.txt", ios::out);
    string s, line, word;

    while (getline(f1, s)) {
        istringstream text(s); //Šajā rindā tiek izveidota teksta virknes plūsma, kas inicializēta ar pašreizējo rindu s.

        while (text >> word) { //Šajā rindā sākas cilpa, kas no teksta plūsmas virknes teksta izraksta katru vārdu, līdz vārdu vairs nav.
            if (line.empty()) { // Ja pašreizējā virkne ir tukša, pievieno pirmo vārdu bez garuma pārbaudes
                line += word;
            } else if (line.size() + word.size() + 1 <= 80) { // Ja, pievienojot nākamo vārdu, netiek pārsniegts virknes maksimālais garums
                line += " " + word;
            } else {
                // Ja, pievienojot nākamo vārdu, tiks pārsniegts maksimālais virknes garums
                // Esošās rindas ierakstīšana un jaunas rindas sākšana
                f2 << line << endl;
                line = word;
            }
        }
    }

    if (!line.empty()) { // Ierakstiet atlikušo virknes daļu
        f2 << line << endl;
    }

    f1.close();
    f2.close();

    return 0;
}