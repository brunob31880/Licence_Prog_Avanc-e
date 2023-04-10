#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include "player.h"

class Computer: public Player
{
public:
    Computer(const char *name);
    ~Computer(void);

    bool play(sPosition *position);
    bool start(void);

private:
    sPosition lastPosition;
};

#endif /* _COMPUTER_H_ */
