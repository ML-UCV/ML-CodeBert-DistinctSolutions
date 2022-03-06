#include <algorithm>
#include <array>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

constexpr int g_maxn = 200'001;

class edge {
   private:
    int m_a = 0;
    int m_b = 0;
    int m_cost = 0;

    using ref = edge &;

   public:
    edge() noexcept = default;
    edge(edge const &) noexcept = default;
    edge(edge &&) noexcept = default;
    ~edge() noexcept = default;

    edge(int const a, int const b, int const cost)
        : m_a{a}, m_b{b}, m_cost{cost} {}

    auto operator=(edge const &) noexcept -> ref = default;
    auto operator=(edge &&) noexcept -> ref = default;

    auto first() const noexcept -> int { return m_a; }
    auto second() const noexcept -> int { return m_b; }
    auto cost() const noexcept -> int { return m_cost; }
};

std::vector<edge> g_edges;
std::vector<edge> g_answer;
std::array<int, g_maxn> g_groups;

auto get_group(int const i) noexcept -> int {
    if (g_groups[i] == i) {
        return i;
    }

    g_groups[i] = get_group(g_groups[i]);

    return g_groups[i];
}

auto unite(int const i, int const j) noexcept -> void {
    g_groups[get_group(i)] = get_group(j);
}

auto main(int, char *[]) noexcept -> int {
    std::ifstream f{"apm.in"};
    std::ofstream g{"apm.out"};

    int n = 0;
    int m = 0;

    f >> n >> m;
    g_edges.reserve(m);
    g_answer.reserve(m);

    for (int i = 0; i < m; ++i) {
        int a = 0;
        int b = 0;
        int cost = 0;

        f >> a >> b >> cost;
        g_edges.emplace_back(a, b, cost);
        g_groups[i] = i;
    }

    std::sort(g_edges.begin(), g_edges.end(),
              [](edge const &a, edge const &b) { return a.cost() < b.cost(); });

    std::int64_t total_cost = 0;
    for (auto const &e : g_edges) {
        if (get_group(e.first()) != get_group(e.second())) {
            total_cost += e.cost();
            unite(e.first(), e.second());
            g_answer.push_back(e);
        }
    }

    g << total_cost << std::endl;
    g << g_answer.size() << std::endl;

    for (auto const &e : g_answer) {
        g << e.first() << ' ' << e.second() << std::endl;
    }
}
