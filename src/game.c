#include "include/game.h"

void _startGame(Game *this) {
    this->_score = 0;
    this->updateScoreDisplay(this);

    ball.setPosX(&ball, 0);
    ball.setPosY(&ball, 0);

    ball.setVelX(&ball, 1);
    ball.setVelY(&ball, 1);

    /*Clear the text from the screen*/
    VDP_clearTextArea(0, 10, 40, 10);

    this->_on = TRUE;
}

void _endGame(Game *this) {
    showText(this->_msgReset);
    this->_on = FALSE;
}

void _updateScoreDisplay(Game *this) {
    sprintf(this->_strScore, "%d", this->_score);
    VDP_clearText(1, 2, 3);
    VDP_drawText(this->_strScore, 1, 2);
}

void _setGameOn(Game *this, u8 on){ this->_on = on; }
void _setGameMsgStart(Game *this, char *msgStart){ sprintf(this->_msgStart, "%s", msgStart); }
void _setGameMsgReset(Game *this, char *msgReset){ sprintf(this->_msgReset, "%s", msgReset); }
void _setGameFlashing(Game *this, int flashing){ this->_flashing = flashing; }
void _setGameFrames(Game *this, int frames){ this->_frames = frames; }
void _setGameScore(Game *this, int score){ this->_score = score; }
void _setGameLabelScore(Game *this, char *labelScore){ sprintf(this->_labelScore, "%s", labelScore); }
void _setGameStrScore(Game *this, char *strScore){ sprintf(this->_strScore, "%s", strScore); }

u8    _getGameOn(Game *this){ return this->_on; }
char* _getGameMsgStart(Game *this){ return this->_msgStart; }
char* _getGameMsgReset(Game *this){ return this->_msgReset; }
int   _getGameFlashing(Game *this){ return this->_flashing; }
int   _getGameFrames(Game *this){ return this->_frames; }
int   _getGameScore(Game *this){ return this->_score; }
char* _getGameLabelScore(Game *this){ return this->_labelScore; }
char* _getGameStrScore(Game *this){ return this->_strScore; }

Game game = {
    ._on       = FALSE,
    ._msgStart = "PRESS START TO BEGIN!\0",
    ._msgReset = "GAME OVER! PRESS START TO PLAY AGAIN.\0",

    ._flashing = FALSE,
    ._frames   = 0,

    ._score      = 0,
    ._labelScore = "SCORE\0",
    ._strScore   = "0",

    .startGame          = _startGame,
    .endGame            = _endGame,
    .updateScoreDisplay = _updateScoreDisplay,

    .setOn         = _setGameOn,
    .setFlashing   = _setGameFlashing,
    .setFrames     = _setGameFrames,
    .setLabelScore = _setGameLabelScore,
    .setMsgReset   = _setGameMsgReset,
    .setMsgStart   = _setGameMsgStart,
    .setScore      = _setGameScore,
    .setStrScore   = _setGameStrScore,

    .getOn         = _getGameOn,
    .getFlashing   = _getGameFlashing,
    .getFrames     = _getGameFrames,
    .getLabelScore = _getGameLabelScore,
    .getMsgReset   = _getGameMsgReset,
    .getMsgStart   = _getGameMsgStart,
    .getScore      = _getGameScore,
    .getStrScore   = _getGameStrScore,

};

