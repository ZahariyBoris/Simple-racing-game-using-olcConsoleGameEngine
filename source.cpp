#include <iostream>
#include "olcConsoleGameEngine.h"
using namespace std;

class OneLoneCoder_FormulaOLC : public olcConsoleGameEngine {
    public:
        OneLoneCoder_FormulaOLC() {
            m_sAppName = L"Formula OLC";
        }
    

    private:


    protected:
        virtual bool OnUserCreate() {
            return true;
        }

        virtual bool OnUserUpdate(float fElapsedTime) {
            return true;
        }
};

int main() {
    
    // Use olcConsoleGameEngine derived app
    OneLoneCoder_FormulaOLC game;
    game.ConstructConsole(160, 100, 8, 8);
    game.Start();

    return 0;
}