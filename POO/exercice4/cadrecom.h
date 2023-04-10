
#ifndef CADRECOM_H_
#define CADRECOM_H_

#include "employe.h"

class CadreCom : public Employe
{
public:
	CadreCom( const char* nom, double salaire, double interessement, double chiffre_ventes );

	void presentation( void );

private:
	double interessement;
	double chiffre_ventes;
};


#endif /* CADRECOM_H_ */
