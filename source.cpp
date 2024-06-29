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
            // Fill screen with black color
            Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ', 0);

            // Draw ground and road
            for (int y = 0; y < ScreenHeight() / 2; y++) {
                for (int x = 0; x < ScreenWidth(); x++) {
                    float fMiddlePoint = 0.5f;
                    float fRoadWidth = 0.6f;
                    float fClipWidth = fRoadWidth * 0.15f;
                    fRoadWidth *= 0.5f;

                    int nLeftGrass = (fMiddlePoint - fRoadWidth - fClipWidth) * ScreenWidth();
                    int nRightGrass = (fMiddlePoint + fRoadWidth + fClipWidth) * ScreenWidth();
                    int nLeftClip = (fMiddlePoint - fRoadWidth) * ScreenWidth(); 
                    int nRightClip = (fMiddlePoint + fRoadWidth) * ScreenWidth();

                    int nRow = ScreenHeight() / 2 + y;

                    if (x >= 0 && x < nLeftGrass) {
                        Draw(x, nRow, PIXEL_SOLID, FG_GREEN);
                    }
                    if (x >= nLeftGrass && x < nLeftClip) {
                        Draw(x, nRow, PIXEL_SOLID, FG_RED);
                    }
                    if (x >= nLeftClip && x < nRightClip) {
                        Draw(x, nRow, PIXEL_SOLID, FG_GREY);
                    }
                    if (x >= nRightClip && x < nRightGrass) {
                        Draw(x, nRow, PIXEL_SOLID, FG_RED);
                    }
                    if (x >= nRightGrass && x < ScreenWidth()) {
                        Draw(x, nRow, PIXEL_SOLID, FG_GREEN);
                    }
                }
            }
            
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