#Django imports
from django import forms
from django.forms import ModelForm, TextInput, Form

#Local Imports
from .choices import *


class SearchBar(forms.Form):
    """ Search bar in the user page """

    name = forms.CharField(max_length=50, label='', required=False,
    widget=forms.TextInput(attrs={'class':'form-field', 'placeholder': 'Search...'}))


class Operation(forms.Form):
    """Checkin/Checkout operation form"""

    CHOICES=[(1,'Check-out'),
         (2,'Check-in')]

    type = forms.ChoiceField(choices=CHOICES, label='', initial=1, widget=forms.RadioSelect)

    user = forms.CharField(max_length=32, label='', required=False,
    widget=forms.TextInput(attrs={'class':'form-field', 'placeholder': 'User ID'}))

    obj1 = forms.CharField(max_length=32, label='', required=False,
    widget=forms.TextInput(attrs={'class':'form-field','id':'obj1', 'placeholder': 'Product 1'}))

    obj2 = forms.CharField(max_length=32, label='', required=False,
    widget=forms.TextInput(attrs={'class':'form-field','id':'obj2', 'placeholder': 'Product 2'}))

    obj3 = forms.CharField(max_length=32, label='', required=False,
    widget=forms.TextInput(attrs={'class':'form-field','id':'obj3', 'placeholder': 'Product 3'}))

    obj4 = forms.CharField(max_length=32, label='', required=False,
    widget=forms.TextInput(attrs={'class':'form-field','id':'obj4', 'placeholder': 'Product 4'}))

    obj5 = forms.CharField(max_length=32, label='', required=False,
    widget=forms.TextInput(attrs={'class':'form-field','id':'obj5', 'placeholder': 'Product 5'}))
