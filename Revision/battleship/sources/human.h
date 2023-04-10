#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "player.h"

class Human: public Player
{
public:
    Human(const char *name);
    ~Human(void);

    bool play(sPosition *position);
    bool start(void);
};

#endif /* _HUMAN_H_ */
