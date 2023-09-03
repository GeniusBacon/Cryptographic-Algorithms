#include "T4_playfair.h"

string T4_playfair::Encrypt_playfair(string p, string key)
{

    string cipher = p;
    for (int i = 0; i < p.size(); i++)
    {
        p[i] = tolower(p[i]);
    }

    for (int i = 0; i < p.size(); i += 2)
    {
        if (p[i] < 'a' || p[i] > 'z')
        {
            i--;
            continue;
        }

        if (i == p.size() - 1)
        {
            p += 'z';
            cipher += 'z';
        }
        else if (p[i + 1] < 'a' || p[i + 1] > 'z')
        {
            p.insert(i + 1, "z");
            cipher.insert(i + 1, "z");
        }
        else if (p[i] == p[i + 1])
        {
            p.insert(i + 1, "x");
            cipher.insert(i + 1, "x");
        }
    }

    char matrix[5][5];
    bool written[26] = { 0 };						// key: playfairexample
    int r = 0, c = 0;
    map <char, pair<int, int> > matrix_map;
    for (int i = 0; i < key.size(); i++)
        if (written[key[i] - 'a'] == false)
        {
            written[key[i] - 'a'] = true;		// p l a y f
            matrix[r][c] = key[i];				// i r e x m
            matrix_map[key[i]] = { r, c };
            if (key[i] == 'i')
            {
                written['j' - 'a'] = true;
                matrix_map['j'] = { r, c };
            }
            else if (key[i] == 'j')
            {
                written['i' - 'a'] = true;
                matrix_map['i'] = { r, c };
            }
            if (c == 4)						// b c d g h
            {									// k n o q s
                r++;							// t u v w z
                c = 0;
            }
            else c++;
        }

    for (int i = 0; i < 26; i++)
    {
        if (written[i] == false)
        {
            written[i] = true;
            matrix[r][c] = (char)('a' + i);
            matrix_map[(char)('a' + i)] = { r, c };
            if (i == 'i' - 'a')
            {
                written[i + 1] = true;
                matrix_map['j'] = { r, c };
            }
            if (i == 'j' - 'a')
            {
                written[i - 1] = true;
                matrix_map['i'] = { r, c };
            }
            if (c == 4)
            {
                r++;
                c = 0;
            }
            else c++;
        }
    }

    /* for (int i = 0; i < 5; i++)
     {
         for (int j = 0; j < 5; j++)
             cout << matrix[i][j] << " ";

     cout << endl;
     }*/
     /*for (int i = 0; i < 26; i++)
     {
         cout << matrix_map[i + 'a'].first << " " << matrix_map[i + 'a'].second << endl;
     }*/

    for (int i = 0; i < p.size(); i += 2)
    {
        if (p[i] < 'a' || p[i] > 'z')
        {
            i--;
            continue;
        }
        if (matrix_map[p[i]].second == matrix_map[p[i + 1]].second)
        {
            if (matrix_map[p[i]].first == 4)
                cipher[i] = matrix[0][matrix_map[p[i]].second];
            else
                cipher[i] = matrix[matrix_map[p[i]].first + 1][matrix_map[p[i]].second];

            if (matrix_map[p[i + 1]].first == 4)
                cipher[i + 1] = matrix[0][matrix_map[p[i + 1]].second];
            else
                cipher[i + 1] = matrix[matrix_map[p[i + 1]].first + 1][matrix_map[p[i + 1]].second];
        }

        else if (matrix_map[p[i]].first == matrix_map[p[i + 1]].first)
        {
            if (matrix_map[p[i]].second == 4)
                cipher[i] = matrix[matrix_map[p[i]].first][0];
            else
                cipher[i] = matrix[matrix_map[p[i]].first][matrix_map[p[i]].second + 1];

            if (matrix_map[p[i + 1]].second == 4)
                cipher[i + 1] = matrix[matrix_map[p[i + 1]].first][0];
            else
                cipher[i + 1] = matrix[matrix_map[p[i + 1]].first][matrix_map[p[i + 1]].second + 1];
        }
        else
        {
            cipher[i] = matrix[matrix_map[p[i]].first][matrix_map[p[i + 1]].second];
            cipher[i + 1] = matrix[matrix_map[p[i + 1]].first][matrix_map[p[i]].second];
        }
    }
    return cipher;
}

string  T4_playfair::Decrypt_playfair(string cipher, string key)
{
    string p = cipher;
    char matrix[5][5];
    bool written[26] = { 0 };						// key: playfairexample
    int r = 0, c = 0;
    map <char, pair<int, int> > matrix_map;
    for (int i = 0; i < key.size(); i++)
        if (written[key[i] - 'a'] == false)
        {
            written[key[i] - 'a'] = true;		// p l a y f
            matrix[r][c] = key[i];				// i r e x m
            matrix_map[key[i]] = { r, c };
            if (key[i] == 'i')
            {
                written['j' - 'a'] = true;
                matrix_map['j'] = { r, c };
            }
            else if (key[i] == 'j')
            {
                written['i' - 'a'] = true;
                matrix_map['i'] = { r, c };
            }
            if (c == 4)						// b c d g h
            {									// k n o q s
                r++;							// t u v w z
                c = 0;
            }
            else c++;
        }

    for (int i = 0; i < 26; i++)
    {
        if (written[i] == false)
        {
            written[i] = true;
            matrix[r][c] = (char)('a' + i);
            matrix_map[(char)('a' + i)] = { r, c };
            if (i == 'i' - 'a')
            {
                written[i + 1] = true;
                matrix_map['j'] = { r, c };
            }
            if (i == 'j' - 'a')
            {
                written[i - 1] = true;
                matrix_map['i'] = { r, c };
            }
            if (c == 4)
            {
                r++;
                c = 0;
            }
            else c++;
        }
    }
    for (int i = 0; i < cipher.size(); i += 2)
    {
        if (cipher[i] < 'a' || cipher[i] > 'z')
        {
            i--;
            continue;
        }
        if (matrix_map[cipher[i]].second == matrix_map[cipher[i + 1]].second)		// dn im rz kr dl pb qo
        {
            if (matrix_map[cipher[i]].first == 0)
                p[i] = matrix[4][matrix_map[cipher[i]].second];
            else
                p[i] = matrix[matrix_map[cipher[i]].first - 1][matrix_map[cipher[i]].second];

            if (matrix_map[cipher[i + 1]].first == 0)
                p[i + 1] = matrix[4][matrix_map[cipher[i + 1]].second];
            else
                p[i + 1] = matrix[matrix_map[cipher[i + 1]].first - 1][matrix_map[cipher[i + 1]].second];
        }

        else if (matrix_map[cipher[i]].first == matrix_map[cipher[i + 1]].first)
        {
            if (matrix_map[cipher[i]].second == 0)
                p[i] = matrix[matrix_map[cipher[i]].first][4];
            else
                p[i] = matrix[matrix_map[cipher[i]].first][matrix_map[cipher[i]].second - 1];

            if (matrix_map[p[i + 1]].second == 0)
                p[i + 1] = matrix[matrix_map[cipher[i + 1]].first][4];
            else
                p[i + 1] = matrix[matrix_map[cipher[i + 1]].first][matrix_map[cipher[i + 1]].second - 1];
        }
        else
        {
            p[i] = matrix[matrix_map[cipher[i]].first][matrix_map[cipher[i + 1]].second];
            p[i + 1] = matrix[matrix_map[cipher[i + 1]].first][matrix_map[cipher[i]].second];
        }
    }
    return p;

}


/*
Paris Saint-Germain forward Lionel Messi said he's planning to rethink his soccer future after the 2022 FIFA World Cup, which kicks off in late November.Messi, who scored a goal in Argentina's 3-0 win over Venezuela on Friday night, said he's only focused on the short term, including the national team's preparations for the World Cup after previously clinching a berth in the 32-team field."I don't know what I will do after the World Cup," Messi told reporters. "I am thinking about what is coming. After Qatar, I will have to reassess many things."He added: "Let's hope these [matches] go the best way possible. But for sure after the World Cup many things will change."Messi's career took a major turn in August when Barcelona announced it was unable to finalize a contract extension for the club legend because of La Liga's regulations on player registration.The seven-time Ballon d'Or winner proceeded to sign with PSG, but his first season with the French giants has seen him score just seven goals in 26 appearances across all competitions.After the club was eliminated from the UEFA Champions League by Real Madrid earlier this month, Messi was booed by PSG fans during the next home fixture at the Parc des Princes, a 3-0 win over Bordeaux.It's a response Messi wasn't accustomed to during his time with Barcelona, which stretched more than two decades after arriving to the Spanish club's famed youth academy, La Masia, at the age of 13.Meanwhile, the forward previously retired from the Argentina national team in 2016 after a loss to Chile in the Copa America Centenario final.He later returned to play for La Albiceleste and helped the side captured the 2021 Copa America championship last summer.Messi didn't provide much detail in his comments, particularly on whether he's considering another retirement from international soccer or even thinking about walking away from the sport for good, but the vague nature of his remarks is sure to attract attention.In the meantime, Argentina is back in action Tuesday for an away match against Ecuador in World Cup qualifying.
*/
