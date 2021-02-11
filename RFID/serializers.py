from rest_framework import serializers
from .models import cart


class cartSerializer(serializers.ModelSerializer):
    class Meta:
        model = cart
        fields = ['id', 'object_id']