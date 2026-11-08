#define PHASE_ENUM(X) \
    X(Undefined)      \
    X(Intermediate)   \
    X(Final)

enum class EOpPhase {
#define X(name) name,
    PHASE_ENUM(X)
#undef X
};

#include <string>

std::string ToStringPhase(EOpPhase phase) {
    switch (phase) {
#define X(name) case EOpPhase::name: return #name;
        PHASE_ENUM(X)
#undef X
    }
}
