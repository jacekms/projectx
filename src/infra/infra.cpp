#include "infra.hpp"

namespace SimH3Mining {

// Definition of the global logger instance
Infra::SH3M_Logger logger("SH3M_Log.txt");

//------------------------------------------------------------------------------

Infra::Infra() {
    logger.log("Infra instance created.\n");
}

Infra::~Infra() {
    logger.log("Infra instance destroyed.\n");
}

std::optional<std::reference_wrapper<Infra>> Infra::get_instance() {
    std::call_once(init_instance_flag, &Infra::init_singleton);
    if (instance) {
        return std::ref(*instance);
    } else {
        return std::nullopt;
    }
}

void Infra::init_singleton() {
    instance.reset(new (std::nothrow) Infra);
    if (!instance) {
        std::fprintf(stderr, "Failed to create Infra instance.\n");
    }
}


} // namespace SimH3Mining
