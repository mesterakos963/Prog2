class Teglalap
{
	protected int m_szelesseg;
	protected int m_magassag;
	public void setSzelesseg(int szelesseg){
	m_szelesseg = szelesseg;
	}
	public void setMagassag(int magassag){
		m_magassag = magassag;
		}
	public int getSzelesseg(){
		return m_szelesseg;
		}
	public int getMagassag(){
		return m_magassag;
		}
	public int getTerulet(){
		return m_szelesseg * m_magassag;
		}
}
class Negyzet extends Teglalap
{
	public void setSzelesseg(int szelesseg){
		m_szelesseg = szelesseg;
		m_magassag = szelesseg;
		}
	public void setMagassag(int magassag){
		m_szelesseg = magassag;
		m_magassag = magassag;
		}
}
class LspTest
{
	private static Teglalap getUjTeglalap()
	{
	return new Negyzet();
	}
	public static void main (String args[])
	{
		Teglalap r = LspTest.getUjTeglalap();
		r.setSzelesseg(5);
		r.setMagassag(10);
		System.out.println(r.getTerulet());
	}
}