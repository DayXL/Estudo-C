void cadastrarCliente(void);
void validarNomeCliente(void);
void validarCPF(void);
void validarNumeroCelular(void);
void validarEmail(void);
void verCliente(void);

typedef struct cliente DadosCliente;

struct cliente {

    char nomeDoCliente[100];
    char cpf[12];
    char numero[12];
    char email[100];

};

