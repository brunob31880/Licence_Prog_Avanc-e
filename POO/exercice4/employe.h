
#ifndef EMPLOYE_H_
#define EMPLOYE_H_


class Employe
{
public:
	Employe( const char* nom, double salaire );

	virtual void presentation( void );

private:
	char nom[128];
	double salaire;
};


#endif /* EMPLOYE_H_ */
