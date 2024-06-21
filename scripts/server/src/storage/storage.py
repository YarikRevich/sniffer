from ..dto import RetrievedDataDto


class Storage:
    """Represents storage for the retrieved records."""

    # Represents all the available records.
    __records: list[RetrievedDataDto] = []

    @staticmethod
    def add_record(value: RetrievedDataDto) -> None:
        """Adds new records to the storage."""

        Storage.__records.append(value)

    @staticmethod
    def get_records() -> list[RetrievedDataDto]:
        """Retrieves all the available records."""

        return Storage.__records
