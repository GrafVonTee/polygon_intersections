#pragma once

#include <vector>
#include "GeometryUtils.h"

namespace Manipulator {
    struct FiguresState {
        Geometry::Polygon polygon1;
        Geometry::Polygon polygon2;
        Geometry::Intersection intersection;
    };

    class StatesLibrary {
    private:
        std::vector<FiguresState> m_states;

        StatesLibrary() = default;

    public:
        StatesLibrary(const StatesLibrary &) = delete;
        StatesLibrary &operator=(StatesLibrary &) = delete;

        static StatesLibrary &getInstance() {
            static StatesLibrary instance;
            return instance;
        }

        bool isEmpty() const { return m_states.empty(); }
        size_t getSize() const { return m_states.size(); }

        const FiguresState &getState(size_t stateIndex = -1) const;
        FiguresState &getStateRef(size_t stateIndex = -1);

        void addState(const FiguresState &state);
        void emplaceState(FiguresState &&state);
        void emplaceState(FiguresState &state);

        void addState(const Geometry::Polygon &, const Geometry::Polygon &, const Geometry::Intersection &);
        void emplaceState(Geometry::Polygon &, Geometry::Polygon &, Geometry::Intersection &);

        static void addInputState(const Geometry::Polygon &, const Geometry::Polygon &);
        static void emplaceInputState(Geometry::Polygon &, Geometry::Polygon &);

        void updateState();

        void popState();
    };
}