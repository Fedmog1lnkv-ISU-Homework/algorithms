import numpy as np
import matplotlib.pyplot as plt
import os.path


def read_wave_file(file_path):
    with open(file_path, "rb") as wav_file:
        riff_header = wav_file.read(12) # чтение первых 12 байт заголовка RIFF
        format_chunk_header = wav_file.read(8) # чтение первых 8 байт формата файла
        format_chunk = wav_file.read(16) # чтение остальных байт блока формата файла

        channels = format_chunk[2]
        sample_width = format_chunk[14]
        frame_rate = int.from_bytes(format_chunk[4:8], byteorder="little")
        num_frames = int.from_bytes(format_chunk[8:12], byteorder="little")

        frames = np.frombuffer(wav_file.read(), dtype=np.int16)

    left_channel = frames[::channels] # выбор каждого четвертого элемента в массиве получает левый канал
    right_channel = frames[1::channels] # выбор каждого четвертого элемента начиная со второго элемента получает правый канал

    duration = num_frames / frame_rate
    ts = np.linspace(0, duration, len(left_channel)) # генерация массива временных меток

    return left_channel, right_channel, ts


def plot_wave_file(left_channel, right_channel, ts, file_name):
    fig = plt.figure(figsize=(12, 6))
    fig.suptitle(f"Wav Audio Channels ({file_name})", fontsize=16, fontweight="bold")
    grid = plt.GridSpec(2, 2, width_ratios=[3, 2])

    fig.text(0.5, 0.04, "Time (s)", ha="center", va="center", fontsize=12)
    fig.text(
        0.06,
        0.5,
        "Amplitude",
        ha="center",
        va="center",
        rotation="vertical",
        fontsize=12,
    )

    grid.update(hspace=0.1)

    # Отображаем график с обоими каналами на левой части сетки
    ax1 = fig.add_subplot(grid[0:2, 0])
    ax1.plot(
        ts,
        left_channel,
        color="#820000",
        linestyle="-",
        linewidth=1,
        label="Left Channel",
    )
    ax1.plot(
        ts,
        right_channel,
        color="#4E6C50",
        linestyle="-",
        linewidth=1,
        label="Right Channel",
    )

    leg = fig.legend()
    for line in leg.get_lines():
        line.set_linewidth(4)

    # Отображаем график с левым каналом на правой верхней части сетки
    ax2 = fig.add_subplot(grid[0, 1])
    ax2.plot(ts, left_channel, color="#820000", linestyle="-", linewidth=1)

    # Отображаем график с правым каналом на правой нижней части сетки
    ax3 = fig.add_subplot(grid[1, 1])
    ax3.plot(ts, right_channel, color="#4E6C50", linestyle="-", linewidth=1)

    plt.show()
    # plt.savefig(f"Wav Audio Channels ({file_name}).png")


def process_wave_file(file_path):
    file_name = os.path.basename(file_path)
    left_channel, right_channel, ts = read_wave_file(file_path)
    plot_wave_file(left_channel, right_channel, ts, file_name)


if __name__ == "__main__":
    file_path = "samples/music.wav"
    process_wave_file(file_path)