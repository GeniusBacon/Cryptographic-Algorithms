

#include<string>
#include <map>

using namespace std;
class T4_md5
{
public:
    string GetHash(string);
    string Padding(string);
    string string_to_binary(string);
    string H_md5(string, string);
    string F_Func(string, string, string);
    string G_Func(string, string, string);
    string H_Func(string, string, string);
    string I_Func(string, string, string);
    string Hexa_to_Binary(string);
    string AND(string, string);
    string OR(string, string);
    string NOT(string);
    string XOR(string, string);
    string HexAddition(string, string);
    long long Binary2Decimal(string S);
    string decimal2Hexa(long long);
    string Binary2Hexa(string s);
    string circular_shift(string, bool, int);
    string LittleEndian(string, bool);

    map <int, char> hex_of_decimal{ {1,'1' }, { 2,'2' }, { 3,'3'}, { 4,'4' }, { 5,'5'},
    {6, '6'}, { 7,'7'}, { 8,'8'}, {9, '9' }, {10,'A'},{11,'B'},{12,'C'}
    , {13,'D' }, {14,'E' }, { 15,'F' }, { 0,'0' } };
    map <char, int> decimal_of_hex{ {'1', 1}, { '2', 2 }, { '3', 3 }, { '4', 4 }, { '5', 5 },
 { '6', 6 }, { '7', 7 }, { '8', 8 }, { '9', 9 }, { 'A', 10 }, { 'B', 11 }, { 'C', 12 }
 , { 'D', 13 }, { 'E', 14 }, { 'F', 15 }, { '0', 0 } };

    string A = "67452301", B = "EFCDAB89", C = "98BADCFE", D = "10325476";
    string T[4][16] = { {"D76AA478","E8C7B756","242070DB","C1BDCEEE","F57C0FAF","4787C62A","A8304613","FD469501","698098D8","8B44F7AF","FFFF5BB1","895CD7BE","6B901122","FD987193","A679438E","49B40821"},
                        {"F61E2562","C040B340","265E5A51","E9B6C7AA","D62F105D","02441453","D8A1E681","E7D3FBC8","21E1CDE6","C33707D6","F4D50D87","455A14ED","A9E3E905","FCEFA3F8","676F02D9","8D2A4C8A"},
                        {"FFFA3942","8771F681","6D9D6122","FDE5380C","A4BEEA44","4BDECFA9","F6BB4B60","BEBFBC70","289B7EC6","EAA127FA","D4EF3085","04881D05","D9D4D039","E6DB99E5","1FA27CF8","C4AC5665"},
                        {"F4292244","432AFF97","AB9423A7","FC93A039","655B59C3","8F0CCC92","FFEFF47D","85845DD1","6FA87E4F","FE2CE6E0","A3014314","4E0811A1","F7537E82","BD3AF235","2AD7D2BB","EB86D391"} };
    int x_order[4][16] = { {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
                           {1,6,11,0,5,10,15,4,9,14,3,8,13,2,7,12},
                           {5,8,11,14,1,4,7,10,13,0,3,6,9,12,15,2},
                           {0,7,14,5,12,3,10,1,8,15,6,13,4,11,2,9} };
    int s_order[4][16] = { {7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22},
                           {5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20},
                           {4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23},
                           {6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21} };
};
