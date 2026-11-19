#!/bin/bash
# Harry Potter and the Chamber of Secrets (Nintendo Switch)
# One-step Standalone NSP Builder wrapper script.
set -e

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$REPO_ROOT"

# 1. Compile NRO and NSO binary if not already built
echo "=== Step 1: Building Switch executable ==="
./build_switch.sh

# 2. Package into Standalone NSP
echo "=== Step 2: Packaging Standalone NSP ==="
python3 scripts/build_nsp.py "$@"
