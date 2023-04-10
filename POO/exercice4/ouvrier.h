
#ifndef OUVRIER_H_
#define OUVRIER_H_

#include "employe.h"

class Ouvrier : public Employe
{
public:
	Ouvrier( const char* nom, double salaire );

	void presentation( void );
};


#endif /* OUVRIER_H_ */
