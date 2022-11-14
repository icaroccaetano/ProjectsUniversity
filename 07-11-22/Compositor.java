
public class Compositor {
	String nome;
	String pais;
	Musica musica[];

	public Compositor (String nome, String pais) {
		this.nome = nome;
		this.pais = pais;
	}
	public void listarMusicas () {
		System.out.println ("Musicas de " + this.nome);
		for (Musica k : musica) {
			System.out.println ("Titulo: " + k.titulo);
		}
	}
	public void definirMusicas (String nomeDasMusicas []) {
		for (String k : nomeDasMusicas) {
			new Musica (k, this);
		}
	}
}
