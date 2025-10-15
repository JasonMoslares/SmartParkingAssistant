import React, { useState } from 'react'
import { useNavigate } from 'react-router-dom'
import { handleCreate } from '../API'
import { Form, Input, Typography } from 'antd'
import '../index.css';

function Create() {
    const [values, setValues] = useState({
        parking_name: ''
    })

    const navigate = useNavigate()

    const createLot = (e) => {
        handleCreate(e,values,navigate)
    }

    return (
        <div className='form-container'>
            <div className='lot-form'>
                <Typography.Title level={4}>Add Parking Lot</Typography.Title>
                <Form layout='vertical'>
                    <Form.Item
                        label="Parking Name"
                        name="parking_name"
                        rules={[{ required: true, message: 'Please enter the lot name' }]}>
                            <Input placeholder="Enter Name"
                                    value={values.parking_name}
                                    onChange={(e) => setValues({...values, parking_name: e.target.value })} />
                    </Form.Item>
                    <button type='button' className='editButton' onClick={createLot}>Create</button>
                </Form>
            </div>
        </div>
    );
}

export default Create
