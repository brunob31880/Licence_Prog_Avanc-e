
#ifndef DATE_H_
#define DATE_H_


class Date
{
public:
	Date( int j, int m, int a );

	void affiche( void );

private:
	int jour, mois, annee;
};


#endif /* DATE_H_ */
