
public class Musica {
	String titulo;
	Compositor compositor;
	
	public Musica (String nome, Compositor compositor) {
		this.titulo = nome;
		this.compositor = compositor;
	}
	public void mostrarCompositor () {
		System.out.println("Compositor: " + this.compositor.nome + "(" + this.compositor.pais + ")");
	}
}
