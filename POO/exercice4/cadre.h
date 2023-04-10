
#ifndef CADRE_H_
#define CADRE_H_

#include "employe.h"

class Cadre : public Employe
{
public:
	Cadre( const char* nom, double salaire, double prime );

	void presentation( void );

private:
	double prime;
};


#endif /* CADRE_H_ */
