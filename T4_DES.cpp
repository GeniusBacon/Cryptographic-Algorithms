#include "T4_DES.h"
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <bitset>


using namespace std;

string T4_DES::Encrypt(string p, string k)
{
    if (k.size() < 16)
    {
        cout << "Please choose a key conatining 16 characters." << endl;
        return "";
    }
    //string key = String2Binary(k);
    Key_Generation(k);
    string Expanded;
    vector<string> Plain_Blocks;
    vector<string> Cipher_Blocks;

    Plain_Blocks = String2Blocks(p, 8);

    for (int i = 0; i < Plain_Blocks.size(); i++)
    {
        string subStrings[8];
        string p_bin = String2Binary(Plain_Blocks[i]);
        p_bin = permutation(p_bin, IP, -1);



        string left_part[17], right_part[17];
        left_part[0] = p_bin.substr(0, p_bin.size() / 2), right_part[0] = p_bin.substr(p_bin.size() / 2, p_bin.npos);
        for (int j = 0; j < 16; j++)
        {
            string Sboxes;
            Expanded = permutationM2(right_part[j], E_selectionTable);
            string XOROperation = Expanded;
            //cout << right_part[j] << endl;
            //cout << "XOR of" << j << " : " << Expanded<<" "<< subkeys[j + 1] << endl;

            for (int k = 0; k < Expanded.size(); k++)
                if (Expanded[k] == subkeys[j + 1][k])
                    XOROperation[k] = '0';
                else
                    XOROperation[k] = '1';

            //cout << "xoroperation" << j << " : " << XOROperation << endl;

            for (int l = 0; l < 8; l++)
            {
                subStrings[l] = XOROperation.substr(l * 6, 6);
                Sboxes += sBoxOperation(subStrings[l], S[l]);
            }

            string finalRight = permutationM2(Sboxes, SboxesPermutation);
            for (int m = 0; m < finalRight.size(); m++)
                if (finalRight[m] == left_part[j][m])
                    finalRight[m] = '0';
                else
                    finalRight[m] = '1';

            //cout << "FinalRight" << j << ": " << finalRight << endl;
            right_part[j + 1] = finalRight;
            left_part[j + 1] = right_part[j];

            //cout << "Left Part" << j+1 << " :" << left_part[j+1]<<endl;
            //cout << "Right Part" << j+1 << " :" << right_part[j+1] << endl;*/


        }
        string concatStr;
        concatStr += right_part[16];		// temp for the assignment
        concatStr += left_part[16];
        //cout << endl << endl << endl << endl;

        string FPstring = permutationM2(concatStr, IPinverse);
        //cout << endl << "Final  " << FPstring << endl;
        Cipher_Blocks.push_back(FPstring);

    }
    string FinalCipher;
    for (int i = 0; i < Cipher_Blocks.size(); i++)
    {
        FinalCipher += Cipher_Blocks[i];
    }
    //cout << FinalCipher << endl;
    //FinalCipher = Binary2String(FinalCipher);
    //cout << FinalCipher << endl;

    return FinalCipher;
}



string T4_DES::Decrypt(string c, string k)
{

    if (k.size() < 16)
    {
        cout << "Please choose a key conatining 16 characters." << endl;
        return "";
    }
    Key_Generation(k);
    string Expanded;
    vector<string> Plain_Blocks;
    vector<string> Cipher_Blocks;


    Cipher_Blocks = String2Blocks(c, 64);
    for (int i = 0; i < Cipher_Blocks.size(); i++)
    {

        string subStrings[8];
        string c_bins= Cipher_Blocks[i];
        string c_bin = permutation(c_bins, IP, -1);
        string left_part[17], right_part[17];
                right_part[16] = c_bin.substr(0, c_bin.size() / 2), left_part[16] = c_bin.substr(c_bin.size() / 2, c_bin.npos);	// ??
        for (int j = 16; j > 0; j--)
        {
            string Sboxes;

            // R15 =L16
            right_part[j - 1] = left_part[j];
            //Expand R15 into 48 bits

            Expanded = permutationM2(right_part[j - 1], E_selectionTable);
            string XOROperation = Expanded;
            //XOR WITH K16
            XOROperation = XOR(Expanded, subkeys[j]);
            for (int l = 0; l < 8; l++)
            {
                subStrings[l] = XOROperation.substr(l * 6, 6);
                Sboxes += sBoxOperation(subStrings[l], S[l]);
            }

            string finalRight = permutationM2(Sboxes, SboxesPermutation);

            left_part[j - 1] =  XOR(finalRight, right_part[j]);

        }

        string Plain;
        Plain += left_part[0];
        Plain += right_part[0];
        Plain = permutation(Plain, IPinverse, -1);

        Plain_Blocks.push_back(Plain);

    }
    string FinalPlain;
    for (int i = 0; i < Plain_Blocks.size(); i++)
    {
        FinalPlain += Plain_Blocks[i];
    }
    FinalPlain = Binary2String(FinalPlain);

    return FinalPlain;
}


void T4_DES::Key_Generation(string k)
{

    k = permutationM2(k, PC_1);				// generating 16 sub-keys
    //k = remove_paritychecks(k, 8);

    subkeys[0] = k;
    string c = k.substr(0, k.size() / 2), d = k.substr(k.size() / 2, k.size() - 1);
    for (int i = 1; i <= 16; i++)
    {
        int bits = 2;
        if (i == 1 || i == 2 || i == 9 || i == 16)
            bits = 1;
        c = circular_shift(c, 1, bits);
        d = circular_shift(d, 1, bits);
        subkeys[i] = {};
        subkeys[i] += c;
        subkeys[i] += d;
        subkeys[i] = permutationM2(subkeys[i], PC_2);

    }


}


string T4_DES::String2Binary(string S)
{
    string S_bin;
    for (int i = 0; i < S.size(); i++)
    {
        char tmp[8] = { '0','0','0','0','0','0','0','0' };
        _itoa_s((int)(S[i]), tmp, 2);
        for (int i = 0; i < 8; i++)
            if (tmp[i] != '0' && tmp[i] != '1')
                S_bin.append("0");
        S_bin += tmp;
    }
    return S_bin;
}

vector<string> T4_DES::String2Blocks(string S, int size)
{
    vector<string> blocks;
    for (int i = 0; i < S.size(); i += size)
    {
        string tmp;
        for (int j = 0; j < size; j++)
            tmp += " ";
        for (int j = 0; j < size; j++)
        {
            if (i + j < S.size())
                tmp[j] = S[i + j];
            else break;
        }
        blocks.push_back(tmp);
    }
    return blocks;
}

string T4_DES::permutation(string Bin, vector<vector<int>> P, int parityOrder)
{
    string S = Bin;
    int id = 0;
    for (int i = 0; i < P.size(); i++)
        for (int j = 0; j < P[i].size(); j++)
        {
            S[id++] = Bin[P[i][j] - 1];
            if (parityOrder != -1 && (id + 1) % parityOrder == 0)
                id++;
        }
    return S;
}

string T4_DES::remove_paritychecks(string k, int parityOrder)
{
    string tmp;
    for (int i = 0; i < k.size(); i++)
        if ((i + 1) % parityOrder)
            tmp += k[i];

    return tmp;
}

string T4_DES::circular_shift(string S, bool left, int bits)
{
    while (bits--)
    {
        if (left)
        {
            S += S[0];
            S.erase(S.begin());
        }
        else					// right shift not needed
        {
            S.insert(S.begin(), S[S.size() - 1]);
            S.erase(S.end() - 1);
        }
    }
    return S;
}

string T4_DES::permutationM2(string rightHalf, vector<vector<int>> ST)
{
    string s = "";
    for (int i = 0; i < ST.size(); i++)
    {
        for (int j = 0; j < ST[i].size(); j++)
        {
            s.append(1, rightHalf[ST[i][j] - 1]);
        }
    }
    return s;
}

string T4_DES::sBoxOperation(string XORSubStrings, vector<vector<int>> SBox)
{

    char rowBinFirst = XORSubStrings[0];
    char rowBinSecond = XORSubStrings[XORSubStrings.size() - 1];
    string Rowstr;
    Rowstr += rowBinFirst;
    Rowstr += rowBinSecond;

    string	Colstr = XORSubStrings.substr(1, (XORSubStrings.size() - 2));
    int Row = stoi(Rowstr, 0, 2);
    int Col = stoi(Colstr, 0, 2);

    int S = SBox[Row][Col];
    string Binary = bitset<4>(S).to_string();

    return	Binary;
}

string T4_DES::XOR(string first,string second)
{
    string output = first;
    for (int k = 0; k < first.size(); k++)
        if (first[k] == second[k])
            output[k] = '0';
        else
            output[k] = '1';

    return output;
}

string T4_DES::Binary2String(string S)
{
    string res;
    for (int i = 0; i < S.size(); i += 8)
    {
        string tmp = S.substr(i, 8);
        res += (char)(bitset<8>(tmp).to_ullong());
    }
    return res;
}




