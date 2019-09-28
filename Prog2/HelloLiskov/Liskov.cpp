#include <iostream>

class Teglalap
{
	public:
		int m_szelesseg;
		int m_magassag;
		virtual void setszelesseg(int szelesseg){
			m_szelesseg = szelesseg;
			}
		virtual void setmagassag(int magassag){
		m_magassag = magassag;
		}
		int getszelesseg(){
			return m_szelesseg;
		}
		int getmagassag(){
			return m_magassag;
		}
		int getTerulet(){
			return m_szelesseg * m_magassag;
		}
};

class Negyzet : public Teglalap
{
	public:
		void setszelesseg(int szelesseg){
			m_szelesseg = szelesseg;
			m_magassag = szelesseg;
			}
		void setmagassag(int magassag){
			m_szelesseg = magassag;
			m_magassag = magassag;
			}
};

Teglalap* getNewTeglalap()
{
	return new Negyzet();
}

int main ()
{
	Teglalap* r = getNewTeglalap();
	r->setszelesseg(5);
	r->setmagassag(10);
	std::cout << r->getTerulet();
}