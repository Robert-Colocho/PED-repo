#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

struct Player {
    int id;
    string nombre;
    int nivel;
    string clase;
    int poder;

    bool operator<(const Player &other) const {
        return id < other.id; // ordenar por id en el set
    }
};

ostream& operator<<(ostream &os, const Player &p) {
    os << "ID:" << p.id << " | " << p.nombre << " | Nivel:" << p.nivel
       << " | Clase:" << p.clase << " | Poder:" << p.poder;
    return os;
}

// Añade jugador a todas las estructuras solicitadas
void addPlayer(set<Player> &playersById,
               map<string, set<int>> &classToIds,
               unordered_map<int, Player> &idToPlayer,
               vector<int> &levels,
               const Player &p) {
    // Evitar duplicados por id
    if (idToPlayer.find(p.id) != idToPlayer.end()) return;

    playersById.insert(p);
    classToIds[p.clase].insert(p.id);
    idToPlayer[p.id] = p;
    levels.push_back(p.nivel);
}

// Muestra todos los jugadores ordenados por id (set)
void showPlayersById(const set<Player> &playersById) {
    cout << "Jugadores ordenados por ID:\n";
    for (const auto &p : playersById) cout << p << '\n';
}

// Muestra el map clase -> set<id>
void showClassMap(const map<string, set<int>> &classToIds) {
    cout << "\nClasificacion por clase (clase : [ids]):\n";
    for (const auto &kv : classToIds) {
        cout << kv.first << " : [";
        bool first = true;
        for (int id : kv.second) {
            if (!first) cout << ", ";
            cout << id;
            first = false;
        }
        cout << "]\n";
    }
}

// Buscar nivel usando binary_search (necesita vector ordenado)
bool searchLevel(vector<int> levels) {
    sort(levels.begin(), levels.end());
    int target;
    cout << "\nIngrese el nivel a buscar: ";
    if (!(cin >> target)) {
        cin.clear();
        string dummy;
        getline(cin, dummy);
        return false;
    }
    bool found = binary_search(levels.begin(), levels.end(), target);
    cout << "Nivel " << target << (found ? " encontrado\n" : " NO encontrado\n");
    return found;
}

// Filtrar jugadores con poder > threshold
vector<Player> filterByPower(const unordered_map<int, Player> &idToPlayer, int threshold) {
    vector<Player> res;
    for (const auto &kv : idToPlayer) {
        if (kv.second.poder > threshold) res.push_back(kv.second);
    }
    return res;
}

// Obtener top N jugadores por poder (descendente)
vector<Player> topNByPower(const unordered_map<int, Player> &idToPlayer, size_t N) {
    vector<Player> all;
    all.reserve(idToPlayer.size());
    for (const auto &kv : idToPlayer) all.push_back(kv.second);
    sort(all.begin(), all.end(), [](const Player &a, const Player &b) {
        return a.poder > b.poder; // desc
    });
    if (all.size() > N) all.resize(N);
    return all;
}

int main() {
    set<Player> playersById;
    map<string, set<int>> classToIds;
    unordered_map<int, Player> idToPlayer;
    vector<int> levels;

    // Datos de ejemplo
    vector<Player> initial = {
        {1, "Aldric", 45, "Guerrero", 88},
        {2, "Belia", 52, "Mago", 92},
        {3, "Ciro", 37, "Arquero", 74},
        {4, "Diana", 60, "Guerrero", 99},
        {5, "Eron", 29, "Mago", 65},
        {6, "Fiora", 50, "Arquero", 85},
        {7, "Galen", 40, "Guerrero", 70},
        {8, "Helena", 55, "Mago", 95}
    };

    for (const auto &p : initial) addPlayer(playersById, classToIds, idToPlayer, levels, p);

    // Mostrar jugadores ordenados por id
    showPlayersById(playersById);

    // Mostrar clasificacion por clase
    showClassMap(classToIds);

    // Acceso rapido por id
    cout << "\nAcceso rapido por ID (unordered_map):\n";
    int queryId = 4;
    auto it = idToPlayer.find(queryId);
    if (it != idToPlayer.end()) cout << "Encontrado ID " << queryId << ": " << it->second << '\n';
    else cout << "ID " << queryId << " no encontrado\n";

    // Mostrar vector de niveles y usar binary_search
    cout << "\nNiveles (sin ordenar): ";
    for (int n : levels) cout << n << " ";
    cout << '\n';

    // Buscar nivel con binary_search (se pide interacción)
    searchLevel(levels);

    // Filtrar por poder > umbral
    int threshold = 80;
    cout << "\nFiltrar jugadores con poder > " << threshold << ":\n";
    auto strong = filterByPower(idToPlayer, threshold);
    for (const auto &p : strong) cout << p << '\n';

    // Top 3 jugadores mas fuertes
    cout << "\nTop 3 jugadores por poder:\n";
    auto top3 = topNByPower(idToPlayer, 3);
    for (size_t i = 0; i < top3.size(); ++i) cout << (i+1) << ") " << top3[i] << '\n';

    return 0;
}
