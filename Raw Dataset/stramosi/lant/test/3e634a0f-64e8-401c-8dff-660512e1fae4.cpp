#include <algorithm>
#include <cassert>
#include <fstream>
#include <functional>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
constexpr const char newl = '\n';



struct Question

{

    int person_id;

    int ancestor_level;

    int ancestor_id;

};



struct Problem

{

    int N, M;

    std::vector<int> parents;

    std::vector<std::vector<int>> children;

    std::vector<Question> questions;



    std::unordered_map<int, std::vector<std::reference_wrapper<Question>>> questions_by_person;



    auto read_input()

    {

        std::ifstream in{"stramosi.in"};

        assert(in);



        in >> N >> M;

        assert(in);



        parents.resize(N + 1);

        children.resize(N + 1);



        parents[0] = 0;





        for (int person_id = 1; person_id < static_cast<int>(parents.size()); ++person_id)

        {

            int parent_id;

            in >> parent_id;

            assert(in);



            parents[person_id] = parent_id;



            children[parent_id].push_back(person_id);

        }



        questions.resize(M);





        for (Question& question : questions)

        {

            in >> question.person_id >> question.ancestor_level;

            assert(in);



            questions_by_person[question.person_id].emplace_back(question);

        }

    }



    auto solve_impl()

    {

        std::vector<int> frontier_impl{};

        frontier_impl.reserve(N / 2);

        std::stack<int, std::vector<int>> frontier{std::move(frontier_impl)};



        std::vector<int> path;

        path.reserve(N + 1);



        frontier.push(0);



        while (!frontier.empty())

        {



            int selected_person_id = frontier.top();

            frontier.pop();





            auto parent_of_selected_it =

                std::find(path.rbegin(), path.rend(), parents[selected_person_id]);

            if (parent_of_selected_it != path.rend() &&

                (parent_of_selected_it + 1).base() != path.end() &&

                (parent_of_selected_it + 1).base() + 1 != path.end())

            {

                path.erase((parent_of_selected_it + 1).base() + 1, path.end());

            }

            path.push_back(selected_person_id);





            auto it = questions_by_person.find(selected_person_id);

            if (it != questions_by_person.end())

            {

                for (Question& question : it->second)

                {

                    int path_idx = static_cast<int>(path.size() - 1 - question.ancestor_level);

                    if (path_idx <= 0)

                        question.ancestor_id = 0;

                    else

                        question.ancestor_id = path[path_idx];

                }

            }





            for (int& child : children[selected_person_id])

            {

                frontier.push(child);

            }

        }

    }



    auto write_out()

    {

        std::ofstream out{"stramosi.out"};

        assert(out);



        for (auto& question : questions)

        {

            out << question.ancestor_id << newl;

            assert(out);

        }

    }



    auto solve()

    {

        read_input();

        solve_impl();

        write_out();

    }

};



int main()

{

    Problem problem;



    problem.solve();

}
