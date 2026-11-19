#!/bin/bash
# Build HarryPotter2.nro for Nintendo Switch.
# If /opt/devkitpro is not installed locally, runs itself inside the official
# devkitpro/devkita64 Docker image.
set -e

if [ ! -d "/opt/devkitpro" ]; then
    echo "Running build inside devkitpro/devkita64 container..."
    docker run --rm -v "$PWD:/work" -w /work devkitpro/devkita64:latest ./build_switch.sh "$@"
    exit $?
fi

export DEVKITPRO=/opt/devkitpro
export DEVKITA64=/opt/devkitpro/devkitA64
export PATH=$DEVKITA64/bin:$DEVKITPRO/tools/bin:$PATH

echo "=== GCC ==="
aarch64-none-elf-g++ --version | head -n 1

echo "=== CMAKE CONFIGURE ==="
cmake --preset switch-arm64 "$@"

echo "=== BUILD HARRY POTTER 2 NRO ==="
cmake --build --preset switch-arm64 --target HarryPotter2

if [ -f "out/switch-arm64/hp2_game.elf" ]; then
    echo "=== GENERATE NSO (main) ==="
    elf2nso out/switch-arm64/hp2_game.elf out/switch-arm64/main
fi

if [ -f "out/switch-arm64/HarryPotter2.nro" ]; then
    echo "=== SUCCESS ==="
    echo "Built NRO: out/switch-arm64/HarryPotter2.nro"
    echo "Built NSO: out/switch-arm64/main"
fi
