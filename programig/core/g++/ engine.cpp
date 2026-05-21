#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[H";
}

void progressBar(double value, const string& label = "") {
    if (!label.empty()) {
        cout << label << " ";
    }
    
    cout << "S > SCANNER [";
    
    int width = 40;
    int filled = (int)(value / 100.0 * width);
    
    for (int i = 0; i < width; i++) {
        if (i < filled)
            cout << "\033[1;36m█\033[0m";      // ពណ៌ខៀវ
        else
            cout << "\033[1;30m░\033[0m";      // ពណ៌ប្រផេះ
    }
    
    cout << "] ";
    cout << fixed << setprecision(2) << value << "%";
    cout << endl;
}

int main() {
    srand(time(0));
    double progress = 0.0;
    
    while (true) {
        clearScreen();
        
        // Header
        cout << "\033[1;35m╔══════════════════════════════════════════════════════════════╗\033[0m\n";
        cout << "\033[1;36m║              CYBER SCANNER ENGINE v2.1                    ║\033[0m\n";
        cout << "\033[1;35m╚══════════════════════════════════════════════════════════════╝\033[0m\n\n";
        
        // បង្កើន progress បន្តិចម្តងៗ (មើលទៅ smooth ជាងមុន)
        progress += (rand() % 180 + 20) / 100.0;   // 0.2 \~ 2.0
        
        if (progress > 100.0) progress = 100.0;
        
        progressBar(progress, "\033[1;37mMAIN SCAN\033[0m");
        
        cout << "\n\033[1;33mSTATUS: \033[1;32mACTIVE\033[0m\n";
        cout << "\033[1;33mTARGET: \033[1;32mLOCKED ONLINE\033[0m\n";
        cout << "\033[1;33mENCRYPTION: \033[1;32mAES-256\033[0m\n\n";
        
        progressBar(progress, "\033[1;37mPACKET ANALYSIS\033[0m");
        
        if (progress >= 100.0) {
            clearScreen();
            cout << "\033[1;32m\n";
            cout << "╔══════════════════════════════════════════════════════════════╗\n";
            cout << "║               SCAN COMPLETED SUCCESSFULLY!                 ║\n";
            cout << "║         TARGET FULLY COMPROMISED - ACCESS GRANTED          ║\n";
            cout << "╚══════════════════════════════════════════════════════════════╝\033[0m\n\n";
            break;
        }
        
        this_thread::sleep_for(chrono::milliseconds(80));
    }
    
    cout << "\033[1;36mPress any key to exit...\033[0m";
    cin.get();
    return 0;
}0
