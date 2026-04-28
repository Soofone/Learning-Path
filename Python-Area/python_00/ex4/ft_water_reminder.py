def ft_water_reminder() -> None:
    last_time = int(input("Days since last watering: "))
    if (last_time > 2):
        print("Water the plants!")
    else:
        print("Plants are fine")
