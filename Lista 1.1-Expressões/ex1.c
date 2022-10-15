
int main () {

	double salario_min;
	double quant_kw;
	
	
	scanf("%lf", &salario_min);
	scanf("%lf", &quant_kw);
	
	double custo_kw = salario_min*0.007;
	double custo_cons = custo_kw*quant_kw;
	double custo_desc = custo_cons*0.9;

	printf("Custo por kW: R$ %.2lf\n", custo_kw);
	printf("Custo do consumo: R$ %.2lf\n", custo_cons);
	printf("Custo com desconto: R$ %.2lf\n", custo_desc);




	return 0;
}



