#include <map>
#include <string>
#include <iostream>
using std::string;

class Solution {
public:
    string addBinary(string a, string b)
    {
        //1110010
        //   1001
        string result;
        size_t a_size = a.size();
        size_t b_size = b.size();
        
        int diff = std::abs((int)a_size - (int)b_size);
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        a.append("0");
        b.append("0");
        
        
        if (a_size >= b_size)
            for(int i = 0; i<diff; i++)
                b.append("0");
        else
            for (int i = 0; i < diff; i++)
                a.append("0");

        for (auto _ : a) result.append("0");

        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());

        a_size = a.size();
        b_size = b.size();
        int remainder = 0;
        for (int i = a_size - 1 ; i >= 0; --i)
        {         
            int   aNum = (int)a.at(i) - 48;
            int   bNum = (int)b.at(i) - 48;
            char& result_num    = result.at(i);
            int sum = aNum + bNum + remainder;
            result_num = sum % 2;
            if (remainder > 0)
                remainder--;
            remainder = sum / 2;
           
            result_num += 48;
           
           
        }
        
        if (result.at(0) == '0')
        {
            std::reverse(result.begin(),result.end());
            result.pop_back();
            std::reverse(result.begin(), result.end());
        }
        return result;
    }
};
int main()
{      

  
    // 111110
    // 100101
    // 110011

    Solution a;
    string result = a.addBinary("111110", "100101");

    std::cout << "first   = 0111110" << "\n";
    std::cout << "second  = 0100101" << "\n";
    std::cout << "correct = 1100011" << "\n";
    std::cout << "result  = " << result;
}