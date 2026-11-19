# Harry Potter and the Chamber of Secrets PC: Mac/Linux/Windows/Web Native

Play the 2002 game with a modern launcher on macOS, Windows, Linux, and Raspberry Pi. A browser build is also available for compatible browsers.

**You need your own copy of the original game.** This project does not include the game's maps, sounds, textures, or other copyrighted game data. The first time you launch, the game asks for your game: either the folder the game was installed to, or the game CD (the disc itself or an `.iso` image of it). The game files are read straight off the CD; the original installer never runs.

## macOS

1. Download the latest **macOS arm64 DMG** from [Releases](https://github.com/cefege/harry-potter-2-chamber-of-secrets-pc/releases/latest).
2. Open the DMG and drag **HarryPotter2** into **Applications**.
3. Open **HarryPotter2**. If macOS blocks the app, open **System Settings → Privacy & Security**, then choose **Open Anyway**.
4. The launcher asks you to **Choose your game folder**: select the folder the game was installed to (it contains `Maps`, `System`, and `Textures`), or the game CD. If you have the CD as an `.iso` file, choose **I have the game CD as an .iso file** instead.
5. Choose **Start playing**, or **Continue** once you have a save.

The app also installs through Homebrew:

```sh
brew tap cefege/hp2 https://github.com/cefege/harry-potter-2-chamber-of-secrets-pc
brew install --cask cefege/hp2/harry-potter-2
```

## Windows 10/11 (64-bit)

The published `v0.1.0` release currently has the macOS download only. The Windows ZIP will be added to the next release. After it appears on [Releases](https://github.com/cefege/harry-potter-2-chamber-of-secrets-pc/releases/latest):

1. Download the **Windows x64 ZIP** and choose **Extract All**. Keep all extracted files together.
2. Double-click **HarryPotter2.exe**.
3. The launcher asks you to **Choose your game folder**: select your installed game folder or the game CD, or choose **I have the game CD as an .iso file**.
4. Choose **Start playing**, or **Continue** once you have a save.

This is a portable app; there is no installer. Your game data and saves are kept separately under your Windows user profile. The ZIP contains the runtime files it needs, but not the original game data.

## Linux

There is currently no Linux installer in Releases. Build the game once on your Linux computer. The commands below are for Debian or Ubuntu; Raspberry Pi OS is covered in the next section.

1. Open Terminal and install the required packages:

   ```sh
   sudo apt update
   sudo apt install -y build-essential clang make cmake ninja-build pkg-config git python3 \
     libarchive-tools libgtk-3-dev libgl1-mesa-dev libegl1-mesa-dev \
     libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxfixes-dev \
     libxi-dev libxss-dev libwayland-dev libxkbcommon-dev libasound2-dev \
     libpulse-dev libfreetype-dev libharfbuzz-dev libfontconfig-dev
   ```

2. Download the project and build it:

   ```sh
   git clone https://github.com/cefege/harry-potter-2-chamber-of-secrets-pc.git
   cd harry-potter-2-chamber-of-secrets-pc
   ```

   For a typical Intel/AMD 64-bit PC:

   ```sh
   cmake --preset linux-x64
   cmake --build --preset linux-x64
   ./dist/linux-x64/bin/hp2_game
   ```

   For a 64-bit ARM Linux computer, use `linux-arm64` instead of `linux-x64` in each command.

3. Import your game folder in the launcher, then choose **New Game** or **Continue**.

Other Linux distributions need the equivalent development packages listed in [the build guide](Docs/BUILDING.md).

## Raspberry Pi 4 or 5

Use **64-bit Raspberry Pi OS with the desktop**. The game is not packaged as a Pi installer yet; build it on the Pi:

1. Open Terminal and install the Debian/Ubuntu packages listed in the Linux section above.
2. Download the project and build the Pi version:

   ```sh
   git clone https://github.com/cefege/harry-potter-2-chamber-of-secrets-pc.git
   cd harry-potter-2-chamber-of-secrets-pc
   cmake --preset linux-arm64
   cmake --build --preset linux-arm64
   ./dist/linux-arm64/bin/hp2_game
   ```

3. Import your own game folder in the launcher. Choose **New Game** to play.

The first launch can take a while while the Pi builds the game. A 32-bit Raspberry Pi OS installation is not supported.

## Nintendo Switch

A native Nintendo Switch port of **Harry Potter and the Chamber of Secrets (PC, 2002)** running on modern OpenGL / EGL and Nintendo Horizon OS (`libnx`).

The port supports two completely independent execution formats:
- **Standalone NSP (Recommended)**: Installed directly to the Nintendo Switch HOME Menu. Assets are self-contained in internal RomFS (zero SD card clutter), saves are managed natively via Switch user account partitions (`save:/`), and the game runs in full Application mode with maximum OS memory priority.
- **Homebrew NRO**: Runs via the Homebrew Launcher (`sdmc:/switch/hp2/HarryPotter2.nro`) with external assets and saves on the SD card (`sdmc:/switch/hp2/User/Save`).

---

### Features & Performance

- **Silky 60 FPS Presentation**: Native 1280x720 rendering in handheld mode and 1920x1080 in docked mode.
- **Integrated Hardware Tuning**: Automatically activates Horizon CPU boost (1224 MHz) and GPU boost (384 MHz) on startup for instant map loading (< 5s) and zero frame stutters, restoring clocks to stock on clean exit.
- **Save System & Quick Load**:
  - Automatically loads your latest save (`Slot0/Save0.usa`) on startup if one exists; otherwise starts a fresh game.
  - **Quick Load Combo**: Press **L + R + Plus + Minus** at any time during gameplay to immediately reload your latest save without needing to go to the main menu.
  - **Dual Save Storage**: Automatically detects environment—uses internal NAND user account storage (`save:/`) in NSP mode, and SD card (`sdmc:/switch/hp2/User/Save`) in NRO mode.
- **Full Controller Integration**: Native Joy-Con and Pro Controller mapping with analog sticks, face buttons, triggers, and jump/spell actions.

---

### Installation & Playing

#### Method A: Standalone NSP (Recommended)
1. Transfer `Harry Potter and the Chamber of Secrets [0100485032000000][v0].nsp` to your Switch using **DBI** (via MTP Responder / Title install), **Tinfoil**, or **Goldleaf**.
2. Launch the game directly from your **Switch HOME Menu**.
3. Select your user profile when prompted.
4. **Benefits**:
   - Zero SD clutter: Game data resides safely inside RomFS.
   - Saves are managed in the system NAND save partition (`save:/`) with full Atmosphere and DBI backup support.
   - Full 32 MB save allocation per profile.

#### Method B: Homebrew NRO
1. Copy `HarryPotter2.nro` to your Nintendo Switch SD card:
   ```
   sdmc:/switch/hp2/HarryPotter2.nro
   ```
2. Copy your original PC game folders into `sdmc:/switch/hp2/`:
   ```
   sdmc:/
   └── switch/
       └── hp2/
           ├── HarryPotter2.nro
           ├── Maps/
           ├── Music/
           ├── Sounds/
           ├── system/ (or System/)
           └── Textures/
   ```
3. Launch `HarryPotter2` from the Homebrew Launcher (preferably in Title Override mode: hold `R` while launching any installed game from the HOME menu).

---

### How to Build Your Own Standalone NSP

You can easily package your legally owned PC copy into a standalone installable NSP.

#### Prerequisites
1. **Python 3** installed on your computer.
2. **Nintendo Switch Keys**: A dumped `prod.keys` file from your console (e.g. using Lockpick_RCM).
3. **hacbrewpack**: Download `hacbrewpack` (v3.0+):
   - Windows: Place `hacbrewpack.exe` in your `PATH` or in `tools/hacbrewpack.exe`.
   - Linux: Build and install via `make && sudo make install`.
4. **Compiled Switch Binary**:
   - Run `./build_switch.sh` (using Docker or local devkitA64) to produce `out/switch-arm64/hp2_game.elf` and `out/switch-arm64/main`.

#### Packaging Command
Run the NSP builder script:

```bash
python3 scripts/build_nsp.py --game-dir "/path/to/pc/game/files" --keys "/path/to/prod.keys"
```

**Options**:
- `--game-dir`: Path to the PC installation containing `system/`, `Maps/`, `Textures/`, `Sounds/`, etc.
- `--keys`: Path to your dumped `prod.keys`.
- `--hacbrewpack`: (Optional) Explicit path to `hacbrewpack` executable if not in PATH.
- `--out-dir`: (Optional) Target output directory (defaults to `dist/`).
- `--titleid`: (Optional) Title ID override (defaults to `0100485032000000`).

The builder will stage the ExeFS (`main`, `main.npdm`), Control (`control.nacp`, 256x256 title icon), and RomFS assets (using zero-copy directory junctions on Windows or symlinks on Linux), compile the NCAs, and produce the finalized package:
```
dist/Harry Potter and the Chamber of Secrets [0100485032000000][v0].nsp
```

Alternatively, on Linux/macOS/WSL with Docker, you can run the all-in-one bash script:
```bash
./build_switch_nsp.sh --game-dir "/path/to/pc/game/files" --keys "/path/to/prod.keys"
```

## Browser mode: play on a phone or tablet

Browser mode runs on a computer that hosts the game and sends a secure web link to your phone or tablet. **Android devices with a current Chrome or Firefox browser are the supported mobile option. iPhone and iPad browsers currently cannot run this WebAssembly build.** Check [browser support for WebAssembly Memory64](https://caniuse.com/wf-wasm-memory64) before trying another device.

To play without hosting anything, open [hp2.mihaimateias.com](https://hp2.mihaimateias.com/) in a supported browser. To host it yourself, you need a computer to build and serve the browser version, as described below.

### 1. Build the browser version

On a Mac or Linux computer, install **Git, CMake, Ninja, and Python 3**. From the project folder, install the Emscripten SDK version used by this project and activate it in this terminal:

```sh
git clone --branch 6.0.10 --depth 1 https://github.com/emscripten-core/emsdk.git ../emsdk
../emsdk/emsdk install 6.0.10
../emsdk/emsdk activate 6.0.10
source ../emsdk/emsdk_env.sh
```

Now build the browser version:

```sh
cmake --preset web-wasm64
cmake --build --preset web-wasm64
```

### 2. Start the local web server

In the same project folder, run:

```sh
python3 Build/serve_web.py --bind 127.0.0.1 --port 8080
```

Leave that terminal open. The game is now available on the host computer at <http://127.0.0.1:8080>.

### 3. Open it on your Android phone or tablet

The browser requires HTTPS for its shared-memory feature. For a simple temporary HTTPS link, install [Cloudflare Tunnel (`cloudflared`)](https://developers.cloudflare.com/cloudflare-one/connections/connect-networks/downloads/) on the host computer. Open a second terminal and run:

```sh
cloudflared tunnel --url http://127.0.0.1:8080
```

Open the `https://…trycloudflare.com` link printed in that terminal on the phone or tablet. Keep both terminals and the host computer running while you play. The temporary link can be opened by anyone who has it, so close the tunnel when you're done. **Do not add `--data-root`** to the server command; that option is for development and exposes files from a folder on the host.

On the device, the page asks you to **Choose your game folder**: pick your installed (or extracted) game folder, or choose **I have the game CD as an .iso file** and pick the `.iso`. Everything is read and unpacked inside the browser; nothing is uploaded. The browser saves imported data and game saves in that browser's storage on that device. Other archives (`.zip`, `.7z`) must be extracted before browser import.

Use **Save backup** in the top-right corner to download your saves and settings as a `.zip` file, and **Restore backup** to load that file again, for example after clearing browser data or on another device.

### Hosting it

Each release publishes a container image that serves the complete game at `/` with the required headers:

```sh
docker run -p 8080:8080 ghcr.io/cefege/hp2-web:<tag>
```

Put it behind HTTPS on a stable address. Browser saves belong to the exact origin (scheme, host and port), so changing the address later leaves players' saves behind unless they use **Save backup** / **Restore backup**.

## Troubleshooting

- **The launcher says game data is missing:** select the installed game folder containing `Maps`, `System`, and `Textures`, the game CD, or the CD's `.iso` file. If the `.iso` is currently open as a disc on your computer, eject it first.
- **A browser says it cannot start:** make sure you opened the HTTPS tunnel link, not the host's plain `http://` address. Use a browser that supports WebAssembly Memory64, WebGL2, and cross-origin isolation.
- **Where are saves stored?** The desktop game keeps saves in your normal user data folder. Browser saves stay in the browser's storage on the device where you played.
- **Need help?** Open an [issue](https://github.com/cefege/harry-potter-2-chamber-of-secrets-pc/issues) and include your operating system and the steps that caused the problem. Do not upload copyrighted game files.

## Contributions

Contributions are welcome, including AI-assisted and AI-generated contributions. Please describe what changed, disclose AI assistance, and include the checks you ran. Follow [AGENTS.md](AGENTS.md) and preserve the game's and third-party projects' licenses.

## License

The code is [MIT licensed](LICENSE). Third-party software credits are in [NOTICE.md](NOTICE.md). Original game content is not included; you must supply your own copy.
