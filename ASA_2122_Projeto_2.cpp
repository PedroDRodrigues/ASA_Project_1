/* Pedro Dias Rodrigues 99300 */
#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

int lis(vector<int> vect, int size)
{
    int ending_ref = 0;
    int numberSequences = 0;
    int x[size] = {1};
    int counter[size] = {1};

    for (int i = 0; i < size; i++)
    {
        int var_x = 1;
        int var_counter = 1;

        for (int k = 0; k < i; k++) 
        {
            if (vect[i] > vect[k])
            {
                if (x[k] + 1 > var_x) 
                { 
                    var_x = x[k] + 1; 
                    var_counter = counter[k]; 
                }

                else if (x[k] + 1 == var_x) 
                { 
                    var_counter += counter[k]; 
                }
            }
        }

        x[i] = var_x;
        counter[i] = var_counter;

        if (x[i] > ending_ref) 
        { 
            ending_ref = x[i]; 
            numberSequences = counter[i]; 
        }

        else if (x[i] == ending_ref) 
        { 
            numberSequences = numberSequences + counter[i]; 
        }
    
    }

    cout << ending_ref << " " << numberSequences << endl;
    return ending_ref;
}

int lcis(vector<int> vect, vector<int> vect_1, int size, int size_1)
{
    int max_size = 0;
    int x[size_1] = {0};
    
    for (int i = 0; i < size; i++)
    {
        int longest_size = 0;
        
        for (int k = 0; k < size_1; k++) 
        {
            if (vect[i] == vect_1[k]) 
            { 
                if (x[k] < longest_size + 1) 
                { 
                    x[k] = longest_size + 1; 
                } 
            }

            else if (vect[i] > vect_1[k]) 
            { 
                if (x[k] > longest_size) 
                { 
                    longest_size = x[k]; 
                } 
            }

            if (x[k] > max_size) 
            { 
                max_size = x[k]; 
            }
        }
    } 

    cout << max_size << endl;
    return max_size;
}

int main() {

    int option_final, aux_int;
    string option, entry, entry_1, aux_numbers;
    stringstream option_ss, entry_ss, entry_ss_1;
    vector<int> vect, vect_1;

    getline(cin, option);
    option_ss << option;
    option_ss >> option_final;

    if (option == "1")
    {    
        getline(cin, entry);
        entry_ss << entry;

        while (!entry_ss.eof()) 
        {    
            entry_ss >> aux_numbers;
            if (stringstream(aux_numbers) >> aux_int) { vect.push_back(aux_int); }
            aux_numbers = "";
        }

        int size = vect.size();
        lis(vect, size);
    }

    if (option == "2")
    {    
        set<int> set_0;
        set<int> set_1;
        getline(cin, entry);
        entry_ss << entry;

        while (!entry_ss.eof()) 
        {    
            entry_ss >> aux_numbers;
            if (stringstream(aux_numbers) >> aux_int) 
            { 
                vect.push_back(aux_int);
                set_0.insert(aux_int); 
            }
            aux_numbers = "";
        }

        getline(cin, entry_1);
        entry_ss_1 << entry_1;

        while (!entry_ss_1.eof()) 
        {    
            entry_ss_1 >> aux_numbers;
            if (stringstream(aux_numbers) >> aux_int) 
            {
                if (set_0.find(aux_int) != set_0.end())
                {
                    vect_1.push_back(aux_int);
                    set_1.insert(aux_int); 
                } 
            }
            aux_numbers = "";
        }

        vector<int> intersection;
        for (auto n: vect) 
        {
            if (set_1.find(n) != set_1.end())
            {
                intersection.push_back(n);
            }
        }

        int size = intersection.size(), size_1 = vect_1.size();
        lcis(intersection, vect_1, size, size_1);
    }

    return 0;
}