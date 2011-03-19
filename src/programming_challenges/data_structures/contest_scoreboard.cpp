#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

struct contestant {
    int number;
    int problem;
    int penalty_time;
};

bool compare(pair<int, contestant> i, pair<int, contestant> j) {
    if (i.second.problem > j.second.problem) {
        return true;
    } else if (i.second.problem == j.second.problem) {
        if (i.second.penalty_time < j.second.penalty_time) {
            return true;

        } else if (i.second.penalty_time == j.second.penalty_time) {
            return (i.first > j.first);

        } else {
            return false;
        }
    } else {
        return false;
    }
}

void print(pair<int, contestant> i) {
    cout << i.first << " " << i.second.problem << " " << i.second.penalty_time << endl;
}


int main(int argc, char** argv)
{
    if (argc > 1) {
        ifstream ifs(argv[1]);

        int cases;
        if (ifs.good()) {
            ifs >> cases;
        }

        int n = 0;
        map<int, contestant> contestants;

        while (ifs.good()) {
            string line;
            getline(ifs, line);

            // Skip blank lines
            if (line == "") {
                // Check if we finished a case
                if (!contestants.empty()) {
                    vector< pair<int, contestant> > vec;
                    copy(contestants.begin(), contestants.end(), back_inserter(vec));
                    sort(vec.begin(), vec.end(), compare);
                    for_each(vec.begin(), vec.end(), print);
                    contestants.clear();
                    n++;
                    if (n < cases) {
                        cout << endl;
                    }
                }
                continue;
            }

            // Use this to format input
            istringstream iss(line);

            int number;
            int problem;
            int penalty_time;
            char status;
            iss >> number >> problem >> penalty_time >> status;

            // Make sure that contentstants are initialized
            if (contestants.find(number) == contestants.end()) {
                contestant c;
                c.number = number;
                c.problem = 0;
                c.penalty_time = 0;
                contestants[number] = c;
            }

            if (status == 'C') {
                // 1 assumption I'm making is that once a problem
                // is solved contestants won't attempt to solve again
                // to score more points. The simple way to fix this
                // is to have a set containing problems already solved
                // within the contestant structure.
                contestants[number].problem++;
                contestants[number].penalty_time += penalty_time;
            } else if (status == 'I') {
                contestants[number].penalty_time += 20;

            } else {
               // Ignore other status
            } 
        }
    }

    return 0;
}
