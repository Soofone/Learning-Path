from abc import ABC, abstractmethod
from typing import Any, List, Dict, Union, Optional


class DataStream(ABC):
    def __init__(self, stream_id: str) -> None:
        self.stream_id: str = stream_id
        self.stats: Dict[str, Union[str, int, float]] = {}
        self.display: bool = True

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(
        self,
        data_batch: List[Any],
        criteria: Optional[str] = None
    ) -> List[Any]:
        return data_batch

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return self.stats


class SensorStream(DataStream):
    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id)

    def process_batch(self, data_batch: List[Any]) -> str:
        try:
            if not data_batch or not isinstance(data_batch, List):
                return "Sensor analysis: no valid readings"
            temps = [
                float(x.split(":")[1])
                for x in data_batch
                if isinstance(x, str) and x.lower().startswith("temp:")
            ]
            count = len(data_batch)
            avg = (sum(temps)/len(temps)) if temps else 0.0
            alerts = [t for t in temps if t > 30]
            if alerts:
                print(f"ALERT: {len(alerts)} extreme temperature(s) detected: "
                      f"{[str(t) + '°C' for t in alerts]}")
            self.stats = {
                "stream_id": self.stream_id,
                "type": "Environment Data",
                "processed_count": count,
                "average_temp": avg
            }
            if self.display:
                print(
                    f"Stream ID: {self.stream_id},"
                    f" Type: Environmental Data"
                )
                print(f"Processing sensor batch: [{', '.join([*data_batch])}]")
            return (
                f"Sensor analysis: {count} readings processed,"
                f" avg temp: {avg}°C"
            )
        except Exception as e:
            return f"Sensor stream error: {e}"

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        if criteria == "high":
            return [
                x for x in data_batch
                if isinstance(x, str)
                and x.startswith("temp:")
                and float(x.split(":")[1]) > 30
            ]
        return data_batch

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return self.stats


class TransactionStream(DataStream):
    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id)

    def process_batch(self, data_batch: List[Any]) -> str:
        try:
            if not data_batch or not isinstance(data_batch, List):
                return "Transaction analysis: no valid data"
            net = 0
            count = len(data_batch)
            for x in data_batch:
                if isinstance(x, str):
                    parts = x.split(":")
                    if parts[0] == "buy":
                        net += int(parts[1])
                    elif parts[0] == "sell":
                        net -= int(parts[1])
            self.stats = {
                "stream_id": self.stream_id,
                "type": "Financial Data",
                "processed_count": count,
                "net_flow": net
            }
            if self.display:
                print(
                    f"Stream ID: {self.stream_id},"
                    f" Type: Financial Data"
                )
                print(f"Processing transaction batch: "
                      f"[{', '.join([*data_batch])}]")
            return (
                f"Transaction analysis: {count} operations,"
                f" net flow: {net:+} units"
            )
        except Exception as e:
            return f"Transaction stream error: {e}"

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        if criteria in ("buy", "sell"):
            return [
                x for x in data_batch
                if isinstance(x, str)
                and x.startswith(criteria + ":")
                and int(x.split(":")[1]) > 100
            ]
        return data_batch

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return self.stats


class EventStream(DataStream):
    def __init__(self, stream_id: str) -> None:
        super().__init__(stream_id)

    def process_batch(self, data_batch: List[Any]) -> str:
        try:
            if not data_batch or not isinstance(data_batch, List):
                return "Event analysis: no valid events"
            count = len(data_batch)
            errors = [
                x for x in data_batch
                if isinstance(x, str) and x == "error"
            ]
            error_count = len(errors)
            self.stats = {
                "stream_id": self.stream_id,
                "type": "System Events",
                "processed_count": count,
                "error_count": error_count
            }
            if self.display:
                print(
                    f"Stream ID: {self.stream_id},"
                    f" Type: System Events"
                )
                print(f"Processing event batch: [{', '.join([*data_batch])}]")
            return (
                f"Event analysis: {count} events,"
                f" {error_count} error detected"
            )
        except Exception as e:
            return f"Event stream error: {e}"

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        if criteria in ("error", "login", "logout"):
            return [
                x for x in data_batch
                if isinstance(x, str) and x.lower() == criteria
            ]
        return data_batch

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return self.stats


class StreamProcessor:
    def __init__(self) -> None:
        self.streams: List[DataStream] = []

    def add_stream(self, stream: DataStream) -> None:
        self.streams.append(stream)

    def process_all(self, batches: List[List[Any]]) -> List[Union[str, int]]:
        results = []
        for stream, batch in zip(self.streams, batches):
            try:
                stream.process_batch(batch)
                results.append(stream.stats["processed_count"])
            except Exception as e:
                results.append(f"Stream error: {e}")
        return results


def main() -> None:
    print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===\n")

    try:
        print("Initializing Sensor Stream...")
        sensor = SensorStream("Sensor_001")
        s_batch = ["temp:22.5", "humidity:65", "pressure:1013"]
        print(sensor.process_batch(s_batch))
    except Exception as e:
        print(e)

    try:
        print("\nInitializing Transaction Stream...")
        trans = TransactionStream("TRANS_001")
        t_batch = ["buy:100", "sell:150", "buy:75"]
        print(trans.process_batch(t_batch))
    except Exception as e:
        print(e)

    try:
        print("\nInitializing Event Stream...")
        event = EventStream("EVENT_001")
        e_batch = ["login", "error", "logout"]
        print(event.process_batch(e_batch))
    except Exception as e:
        print(e)

    print("\n=== Polymorphic Stream Processing ===")

    try:
        print("Processing mixed stream types through unified interface...\n")
        processor = StreamProcessor()
        s2 = SensorStream("SENSOR_002")
        t2 = TransactionStream("TRANS_002")
        e2 = EventStream("EVENT_002")
        processor.add_stream(s2)
        processor.add_stream(t2)
        processor.add_stream(e2)

        batches: List[List[Any]] = [
            ["temp:20.1", "humidity:70"],
            ["buy:200", "sell:50", "buy:300", "buy:150"],
            ["login", "error", "logout"]
        ]

        s2.display = False
        t2.display = False
        e2.display = False
        results = processor.process_all(batches)
        print("Batch 1 Results:")
        print(f"- Sensor data: {results[0]} readings processed")
        print(f"- Transaction data: {results[1]} "
              "operations processed")
        print(f"- Event data: {results[2]} events processed")

        print("\nStream filtering active: High-priority data only")
        sensor2 = SensorStream("SENSOR_002")
        trans2 = TransactionStream("TRANS_002")
        s_filtered = sensor2.filter_data(
            ["temp:35.5", "temp:8.0", "temp:40.2"], "high"
        )
        t_filtered = trans2.filter_data(
            ["buy:200", "sell:50"], "buy"
        )
        print(
            f"Filtered results: {len(s_filtered)} critical sensor alerts,"
            f" {len(t_filtered)} large transaction"
        )
    except Exception as e:
        print(e)

    print(
        "\nAll streams processed successfully."
        " Nexus throughput optimal."
    )


if __name__ == "__main__":
    main()
