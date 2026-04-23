#pragma once

#include <global.hpp>


constexpr real_t operator ""_s(long double v)  { return static_cast<real_t>(v); }
constexpr real_t operator ""_s(unsigned long long v)  { return static_cast<real_t>(v); }

constexpr real_t operator ""_ms(long double v) { return static_cast<real_t>(v * 1e-3L); }
constexpr real_t operator ""_ms(unsigned long long v) { return static_cast<real_t>(v) * 1e-3; }

constexpr real_t operator ""_us(long double v) { return static_cast<real_t>(v * 1e-6L); }
constexpr real_t operator ""_us(unsigned long long v) { return static_cast<real_t>(v) * 1e-6; }

constexpr real_t operator ""_ns(long double v) { return static_cast<real_t>(v * 1e-9L); }
constexpr real_t operator ""_ns(unsigned long long v) { return static_cast<real_t>(v) * 1e-9; }

constexpr real_t operator ""_ps(long double v) { return static_cast<real_t>(v * 1e-12L); }
constexpr real_t operator ""_ps(unsigned long long v) { return static_cast<real_t>(v) * 1e-12; }



constexpr real_t operator ""_Hz(long double v)  { return static_cast<real_t>(v); }
constexpr real_t operator ""_Hz(unsigned long long v)  { return static_cast<real_t>(v); }

constexpr real_t operator ""_kHz(long double v) { return static_cast<real_t>(v * 1e3L); }
constexpr real_t operator ""_kHz(unsigned long long v) { return static_cast<real_t>(v) * 1e3; }

constexpr real_t operator ""_MHz(long double v) { return static_cast<real_t>(v * 1e6L); }
constexpr real_t operator ""_MHz(unsigned long long v) { return static_cast<real_t>(v) * 1e6; }

constexpr real_t operator ""_GHz(long double v) { return static_cast<real_t>(v * 1e9L); }
constexpr real_t operator ""_GHz(unsigned long long v) { return static_cast<real_t>(v) * 1e9; }



constexpr real_t operator ""_V(long double v)  { return static_cast<real_t>(v); }
constexpr real_t operator ""_V(unsigned long long v)  { return static_cast<real_t>(v); }

constexpr real_t operator ""_mV(long double v) { return static_cast<real_t>(v * 1e-3L); }
constexpr real_t operator ""_mV(unsigned long long v) { return static_cast<real_t>(v) * 1e-3; }

constexpr real_t operator ""_uV(long double v) { return static_cast<real_t>(v * 1e-6L); }
constexpr real_t operator ""_uV(unsigned long long v) { return static_cast<real_t>(v) * 1e-6; }

constexpr real_t operator ""_kV(long double v) { return static_cast<real_t>(v * 1e3L); }
constexpr real_t operator ""_kV(unsigned long long v) { return static_cast<real_t>(v) * 1e3; }



constexpr real_t operator ""_A(long double v)  { return static_cast<real_t>(v); }
constexpr real_t operator ""_A(unsigned long long v)  { return static_cast<real_t>(v); }

constexpr real_t operator ""_mA(long double v) { return static_cast<real_t>(v * 1e-3L); }
constexpr real_t operator ""_mA(unsigned long long v) { return static_cast<real_t>(v) * 1e-3; }

constexpr real_t operator ""_uA(long double v) { return static_cast<real_t>(v * 1e-6L); }
constexpr real_t operator ""_uA(unsigned long long v) { return static_cast<real_t>(v) * 1e-6; }

constexpr real_t operator ""_nA(long double v) { return static_cast<real_t>(v * 1e-9L); }
constexpr real_t operator ""_nA(unsigned long long v) { return static_cast<real_t>(v) * 1e-9; }



constexpr real_t operator ""_Ohm(long double v)  { return static_cast<real_t>(v); }
constexpr real_t operator ""_Ohm(unsigned long long v)  { return static_cast<real_t>(v); }

constexpr real_t operator ""_kOhm(long double v) { return static_cast<real_t>(v * 1e3L); }
constexpr real_t operator ""_kOhm(unsigned long long v) { return static_cast<real_t>(v) * 1e3; }

constexpr real_t operator ""_MOhm(long double v) { return static_cast<real_t>(v * 1e6L); }
constexpr real_t operator ""_MOhm(unsigned long long v) { return static_cast<real_t>(v) * 1e6; }

constexpr real_t operator ""_mOhm(long double v) { return static_cast<real_t>(v * 1e-3L); }
constexpr real_t operator ""_mOhm(unsigned long long v) { return static_cast<real_t>(v) * 1e-3; }



constexpr real_t operator ""_F(long double v)  { return static_cast<real_t>(v); }
constexpr real_t operator ""_F(unsigned long long v)  { return static_cast<real_t>(v); }

constexpr real_t operator ""_mF(long double v) { return static_cast<real_t>(v * 1e-3L); }
constexpr real_t operator ""_mF(unsigned long long v) { return static_cast<real_t>(v) * 1e-3; }

constexpr real_t operator ""_uF(long double v) { return static_cast<real_t>(v * 1e-6L); }
constexpr real_t operator ""_uF(unsigned long long v) { return static_cast<real_t>(v) * 1e-6; }

constexpr real_t operator ""_nF(long double v) { return static_cast<real_t>(v * 1e-9L); }
constexpr real_t operator ""_nF(unsigned long long v) { return static_cast<real_t>(v) * 1e-9; }

constexpr real_t operator ""_pF(long double v) { return static_cast<real_t>(v * 1e-12L); }
constexpr real_t operator ""_pF(unsigned long long v) { return static_cast<real_t>(v) * 1e-12; }



constexpr real_t operator ""_H(long double v)  { return static_cast<real_t>(v); }
constexpr real_t operator ""_H(unsigned long long v)  { return static_cast<real_t>(v); }

constexpr real_t operator ""_mH(long double v) { return static_cast<real_t>(v * 1e-3L); }
constexpr real_t operator ""_mH(unsigned long long v) { return static_cast<real_t>(v) * 1e-3; }

constexpr real_t operator ""_uH(long double v) { return static_cast<real_t>(v * 1e-6L); }
constexpr real_t operator ""_uH(unsigned long long v) { return static_cast<real_t>(v) * 1e-6; }

constexpr real_t operator ""_nH(long double v) { return static_cast<real_t>(v * 1e-9L); }
constexpr real_t operator ""_nH(unsigned long long v) { return static_cast<real_t>(v) * 1e-9; }



constexpr real_t operator ""_W(long double v)  { return static_cast<real_t>(v); }
constexpr real_t operator ""_W(unsigned long long v)  { return static_cast<real_t>(v); }

constexpr real_t operator ""_mW(long double v) { return static_cast<real_t>(v * 1e-3L); }
constexpr real_t operator ""_mW(unsigned long long v) { return static_cast<real_t>(v) * 1e-3; }

constexpr real_t operator ""_kW(long double v) { return static_cast<real_t>(v * 1e3L); }
constexpr real_t operator ""_kW(unsigned long long v) { return static_cast<real_t>(v) * 1e3; }