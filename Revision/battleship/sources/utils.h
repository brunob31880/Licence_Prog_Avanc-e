#ifndef _UTILS_H_
#define _UTILS_H_

#include "definitions.h"

/**
 * @brief 
 * 
 * @param position 
 * @return true 
 * @return false 
 */
bool askPosition(sPosition *position);
eDirection askDirection(void);
sPosition randomPosition(void);
eDirection randomDirection(void);
bool isPositValid(const sPosition *position, int LIMIT);
#endif /* _UTILS_H_ */
