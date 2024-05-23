#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  setlocale(LC_ALL, "portuguese");
  int a;

  do
  {
    system("cls");
    cout << "Escolha a opção desejada: \n [1] jogar \n [2] sobre \n [3] sair \n";
    cin >> a;
    cout << "\n";

    switch (a)
    {

    case 1:
    {
      system("cls");
      int codigoSecreto1, codigoSecreto2, codigoSecreto3, codigoSecreto4; // código secreto gerado pela máquina
      int palpite1, palpite2, palpite3, palpite4;                         // palpite do jogador
      int tentativasRestantes = 10;                                       // número de tentativas
      int digitosCorretosPosicaoCorreta = 0;                              // dígitos corretos na posição correta
      int digitosCorretosPosicaoErrada = 0;                               // dígitos corretos na posição errada

      // gerar o código secreto aleatoriamente
      srand(time(NULL));
      codigoSecreto1 = rand() % 6 + 1;
      do
      {
        codigoSecreto2 = rand() % 6 + 1;
      } while (codigoSecreto2 == codigoSecreto1);
      do
      {
        codigoSecreto3 = rand() % 6 + 1;
      } while (codigoSecreto3 == codigoSecreto1 || codigoSecreto3 == codigoSecreto2);
      do
      {
        codigoSecreto4 = rand() % 6 + 1;
      } while (codigoSecreto4 == codigoSecreto1 || codigoSecreto4 == codigoSecreto2 || codigoSecreto4 == codigoSecreto3);

      // laço principal do jogo
      while (tentativasRestantes > 0 && digitosCorretosPosicaoCorreta < 4)
      {
        cout << endl
             << "Tentativas restantes: " << tentativasRestantes << endl;
        cout << "Digite seu palpite (4 dígitos): ";

        cin >> palpite1 >> palpite2 >> palpite3 >> palpite4;

        digitosCorretosPosicaoCorreta = 0;
        digitosCorretosPosicaoErrada = 0;

        // verificar se os dígitos corretos estão na posição correta
        if (palpite1 == codigoSecreto1)
        {
          digitosCorretosPosicaoCorreta++;
        }
        if (palpite2 == codigoSecreto2)
        {
          digitosCorretosPosicaoCorreta++;
        }
        if (palpite3 == codigoSecreto3)
        {
          digitosCorretosPosicaoCorreta++;
        }
        if (palpite4 == codigoSecreto4)
        {
          digitosCorretosPosicaoCorreta++;
        }

        // verificar se os dígitos estão corretos na posição errada
        digitosCorretosPosicaoErrada = 0;

        if (palpite1 == codigoSecreto2 || palpite1 == codigoSecreto3 || palpite1 == codigoSecreto4)
        {
          digitosCorretosPosicaoErrada++;
        }

        if (palpite2 == codigoSecreto1 || palpite2 == codigoSecreto3 || palpite2 == codigoSecreto4)
        {
          digitosCorretosPosicaoErrada++;
        }

        if (palpite3 == codigoSecreto1 || palpite3 == codigoSecreto2 || palpite3 == codigoSecreto4)
        {
          digitosCorretosPosicaoErrada++;
        }

        if (palpite4 == codigoSecreto1 || palpite4 == codigoSecreto2 || palpite4 == codigoSecreto3)
        {
          digitosCorretosPosicaoErrada++;
        }

        // essa parte vai ser mostrada para o jogador como dicas
        cout << "Digitos corretos na posição correta: " << digitosCorretosPosicaoCorreta << endl;
        cout << "Digitos corretos, mas na posição errada: " << digitosCorretosPosicaoErrada << endl;
        tentativasRestantes--;
      }

      // se ele acertou aparece mensagem de parabéns
      if (digitosCorretosPosicaoCorreta == 4)
      {
        system("cls");
        cout << endl
             << "Parabéns! Você acertou o código secreto!" << endl;
        system("pause");
      }
      // se ele errou mostra a sequência certa
      else
      {
        system("cls");
        cout << endl
             << "Você perdeu! O código secreto era: " << codigoSecreto1 << " " << codigoSecreto2 << " " << codigoSecreto3 << " " << codigoSecreto4 << endl;
        system("pause");
      }
      break;
    }

    // caso o jogador escolha 2, ele será levado para a opção "Sobre" do jogo
    case 2:
    {
      system("cls");
      cout << "Criadores: João Tavares, Pedro Degen, Júlia Brandelli, Roger Gomes" << endl;
      cout << "Mês/Ano: 05/2024" << endl;
      cout << "Nome do Professor: Rafael Martins" << endl;
      cout << "Matéria: Algoritmos e Programação" << endl;
      system("pause");
      break;
    }

    // jogador saiu do jogo
    case 3:
    {
      system("cls");
      cout << "Você saiu do jogo! :c" << endl;
      break;
    }

    // jogador escolheu um número inválido, solicita que escolha um número válido
    default:
    {
      system("cls");
      cout << "Opção inválida! Digite novamente um número de 1 a 3!" << endl;
      system("pause");
      break;
    }
    }
  } while (a != 3);

  return 0;
}