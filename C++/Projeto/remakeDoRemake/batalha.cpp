/**
 * @file batalha.cpp
 * @brief Implementação do sistema de batalha por turnos.
 */
#include "batalha.h"
#include <iostream>

namespace RPG {

Batalha::Batalha(Personagem &j, Inimigo &i)
    : jogador(j), inimigo(i), turnoAtual(0), encerrada(false) {}

// ── privados ──────────────────────────────────────────────────────────────────

void Batalha::registrar(const std::string &msg) {
    log.push_back({turnoAtual, msg});
}

void Batalha::imprimirSeparador() const {
    std::cout << "──────────────────────────────────────────" << std::endl;
}

void Batalha::menuAcaoJogador() {
    std::cout << "\n[TURNO " << turnoAtual << "] "
              << jogador.getNome() << " — escolha uma ação:\n"
              << "  1. Atacar\n"
              << "  2. Usar Habilidade\n"
              << "  3. Usar Estus\n"
              << "  4. Usar item do inventário\n"
              << "> ";

    int opcao;
    std::cin >> opcao;

    switch (opcao) {
        case 1:
            jogador.atacar(inimigo);
            registrar(jogador.getNome() + " atacou " + inimigo.getNome());
            break;
        case 2:
            menuHabilidade();
            break;
        case 3:
            jogador.usarEstus();
            registrar(jogador.getNome() + " usou Estus Flask");
            break;
        case 4:
            menuItem();
            break;
        default:
            std::cout << "Ação inválida — atacando por padrão." << std::endl;
            jogador.atacar(inimigo);
    }
}

void Batalha::menuHabilidade() {
    const auto& habs = jogador.getHabilidades();
    if (habs.empty()) {
        std::cout << "Sem habilidades disponíveis." << std::endl;
        return;
    }
    std::cout << "Habilidades:\n";
    for (int i = 0; i < static_cast<int>(habs.size()); i++) {
        std::cout << "  " << (i + 1) << ". " << *habs[i] << "\n";
    }
    std::cout << "> ";
    int idx;
    std::cin >> idx;
    idx--;
    jogador.usarHabilidade(idx, inimigo);
    registrar(jogador.getNome() + " usou habilidade");
}

void Batalha::menuItem() {
    Pocao* p = jogador.getInventario().getPocao();
    if (p && p->temCargas()) {
        p->usar();
        jogador.curar(p->getCura());
        std::cout << jogador.getNome() << " usou " << p->getNome()
                  << " — +" << p->getCura() << " HP!" << std::endl;
        registrar(jogador.getNome() + " usou " + p->getNome());
    } else {
        std::cout << "Nenhum consumível disponível." << std::endl;
    }
}

// ── públicos ──────────────────────────────────────────────────────────────────

bool Batalha::executar() {
    std::cout << "\n╔══════════════════════════════════════════╗\n"
              << "║          BATALHA INICIADA!               ║\n"
              << "╚══════════════════════════════════════════╝\n";
    std::cout << jogador << " vs " << inimigo << "\n";
    imprimirSeparador();

    while (jogador.estaVivo() && inimigo.estaVivo()) {
        turnoAtual++;

        // turno do jogador
        menuAcaoJogador();
        jogador.recuperarStamina(25);
        jogador.reduzirCooldowns();

        if (!inimigo.estaVivo()) break;

        // turno do inimigo
        imprimirSeparador();
        inimigo.atacar(jogador);
        registrar(inimigo.getNome() + " atacou " + jogador.getNome());

        // status resumido
        std::cout << "\n» " << jogador << "\n» " << inimigo << "\n";
        imprimirSeparador();
    }

    return resolverFim();
}

bool Batalha::resolverFim() {
    encerrada = true;
    std::cout << "\n╔══════════════════════════════════════════╗\n";
    if (jogador.estaVivo()) {
        std::cout << "║  VITÓRIA! " << jogador.getNome() << " sobreviveu!\n";
        std::cout << "╚══════════════════════════════════════════╝\n";
        jogador.ganharExp(inimigo.getExpRecompensa());
        std::cout << "  Almas obtidas: " << inimigo.getAlmasRecompensa() << "\n";
        jogador.recarregarEstus();
        return true;
    } else {
        std::cout << "║  DERROTA — " << jogador.getNome() << " foi abatido!\n";
        std::cout << "╚══════════════════════════════════════════╝\n";
        std::cout << "  \"YOU DIED\"\n";
        return false;
    }
}

void Batalha::exibirLog() const {
    std::cout << "\n=== LOG DA BATALHA ===\n";
    for (const auto &e : log) {
        std::cout << "[Turno " << e.turno << "] " << e.descricao << "\n";
    }
}

} // namespace RPG
